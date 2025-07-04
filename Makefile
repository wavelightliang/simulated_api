# 编译器定义
CC = gcc

# --- 目录和文件名定义 ---
DIR_APP = src/user_app
DIR_API = src/simulated_api
DIR_KERNEL = src/simulated_kernel
DIR_BUILD = build

TARGET_EXE = user_app.exe
TARGET_DLL = simulated_api.dll
TARGET_LIB = libsimulated_api.a

# --- 源文件列表 ---
SRCS_APP = $(wildcard $(DIR_APP)/*.c)
SRCS_DLL = $(wildcard $(DIR_API)/*.c) $(wildcard $(DIR_KERNEL)/*.c)

# --- 目标文件 (.o) 列表 ---
OBJS_APP = $(patsubst %.c, $(DIR_BUILD)/%.o, $(notdir $(SRCS_APP)))
OBJS_DLL = $(patsubst %.c, $(DIR_BUILD)/%.o, $(notdir $(SRCS_DLL)))

# --- 编译和链接选项 ---
CFLAGS = -Wall -Wextra -g -Isrc
DLL_CFLAGS = -DSIMULATED_API_EXPORTS
EXE_LDFLAGS = -L. -lsimulated_api

# --- 构建规则 ---

.PHONY: all
all: $(TARGET_EXE)

# 构建EXE的规则
# EXE依赖于它自己的.o文件和导入库
$(TARGET_EXE): $(OBJS_APP) $(TARGET_LIB)
	$(CC) -o $@ $(OBJS_APP) $(EXE_LDFLAGS)

# 关键修正：明确声明导入库依赖于DLL
# 这条规则告诉make，要生成.a文件，必须先执行生成.dll文件的规则
$(TARGET_LIB): $(TARGET_DLL)
	# 此处为空命令，因为.a文件是由下面的规则附带生成的
	# 这条规则的核心作用是建立依赖关系

# 构建DLL的规则
$(TARGET_DLL): $(OBJS_DLL)
	$(CC) -shared -o $@ $^ -Wl,--out-implib,$(TARGET_LIB)

# --- 通用模式规则，用于编译 .o 文件 ---

$(DIR_BUILD)/%.o: $(DIR_API)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DLL_CFLAGS) -c -o $@ $<

$(DIR_BUILD)/%.o: $(DIR_KERNEL)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DLL_CFLAGS) -c -o $@ $<

$(DIR_BUILD)/%.o: $(DIR_APP)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

# --- 清理规则 ---
.PHONY: clean
clean:
	rm -f $(TARGET_EXE) $(TARGET_DLL) $(TARGET_LIB)
	rm -rf $(DIR_BUILD)

.PHONY: rebuild
rebuild: clean all
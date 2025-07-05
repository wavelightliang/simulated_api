#include "simulated_kernel.h"
#include <stdio.h>
#include <string.h> // 为了使用 strlen
#include <windows.h> // 为了使用 SetConsoleOutputCP

// 内核引导函数
void Kernel_Bootstrap(void) {
    // 确保在Windows控制台中正确显示UTF-8字符（包括中文）
    SetConsoleOutputCP(CP_UTF8);
    // [修改] 将英文输出替换为中文
    printf("[内核] 模拟内核正在运行。系统就绪。\n");
}

// 内核处理消息框请求的核心函数
void Kernel_HandleMessageRequest(const char* text, const char* caption) {
    // [修改] 将英文输出替换为中文
    printf("[内核] 收到消息请求。正在渲染至控制台...\n");

    // 注意：这里的宽度计算基于字节长度(strlen)，对于中文字符可能不完全精确
    // 但对于教学演示是足够的。
    int text_len = strlen(text);
    int caption_len = strlen(caption);
    int width = (text_len > caption_len ? text_len : caption_len) + 4; // 取较长的那个作为宽度基准

    // 打印上边框
    printf("+");
    for (int i = 0; i < width; ++i) printf("-");
    printf("+\n");

    // 打印标题行
    printf("| %s", caption);
    for (int i = 0; i < width - caption_len - 1; ++i) printf(" ");
    printf("|\n");

    // 打印分隔线
    printf("+");
    for (int i = 0; i < width; ++i) printf("-");
    printf("+\n");

    // 打印内容行
    printf("| %s", text);
    for (int i = 0; i < width - text_len - 1; ++i) printf(" ");
    printf("|\n");

    // [修改] 将 "[ OK ]" 替换为 "[ 确定 ]"
    // 注意：strlen("[ OK ]") 是 6，而 strlen("[ 确定 ]") 在UTF-8下是 8
    // 所以我们需要将下面的数字 6 替换为 8
    printf("|");
    for (int i = 0; i < (width - 8) / 2; ++i) printf(" ");
    printf("[ 确定 ]");
    for (int i = 0; i < width - 8 - (width - 8) / 2; ++i) printf(" ");
    printf("|\n");

    // 打印下边框
    printf("+");
    for (int i = 0; i < width; ++i) printf("-");
    printf("+\n");
}
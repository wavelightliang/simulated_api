#include "simulated_kernel.h"
#include <stdio.h>
#include <string.h> // 为了使用 strlen
#include <windows.h>

// 已有的引导函数
void Kernel_Bootstrap(void) {
    SetConsoleOutputCP(CP_UTF8);
    printf("[Kernel] Simulated Kernel is running. System is ready.\n");
}

// 新增的内核服务实现
void Kernel_HandleMessageRequest(const char* text, const char* caption) {
    printf("[Kernel] Received message request. Rendering to console...\n");

    // 为了美观，我们做一点简单的计算来居中
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

    // 打印一个模拟的按钮
    printf("|");
    for (int i = 0; i < (width - 6) / 2; ++i) printf(" ");
    printf("[ OK ]");
    // 处理奇偶宽度对齐
    for (int i = 0; i < width - 6 - (width - 6) / 2; ++i) printf(" ");
    printf("|\n");

    // 打印下边框
    printf("+");
    for (int i = 0; i < width; ++i) printf("-");
    printf("+\n");
}
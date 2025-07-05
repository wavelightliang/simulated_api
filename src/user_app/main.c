#include "simulated_api/simulated_api.h"
#include <stdio.h>
#include <windows.h>

int main(void) {
    // 在程序的入口点设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // [修改] 将英文输出替换为中文
    printf("[用户程序] 应用程序启动...\n");
    
    printf("[用户程序] 正在调用高级API以初始化系统...\n");
    if (InitializeSystem() == 0) {
        printf("[用户程序] 通过API系统初始化成功。\n\n");
    } else {
        printf("[用户程序] 系统初始化失败。\n");
        return 1; // 返回错误码
    }
    
    printf("[用户程序] 正在调用 Simulated_MessageBoxA API...\n");
    // [修改] 将消息框的英文内容替换为中文
    Simulated_MessageBoxA(
        NULL, 
        "这是一条来自用户程序UserApp的测试消息。", 
        "用户程序消息", 
        0
    );
    printf("[用户程序] Simulated_MessageBoxA API 调用结束。\n\n");

    printf("[用户程序] 正在以不同内容再次调用API...\n");
    Simulated_MessageBoxA(
        NULL,
        "探索第一性原理，洞见技术本质。",
        "学习心得",
        0
    );
    printf("[用户程序] 第二次API调用结束。\n\n");

    printf("[用户程序] 应用程序结束。\n");
    
    return 0;
}
#include "simulated_api.h"
#include "simulated_kernel/simulated_kernel.h"
#include <stdio.h>

// 初始化整个模拟系统
int InitializeSystem(void) {
    // [修改] 将英文输出替换为中文
    printf("[模拟API] 收到系统初始化请求。\n");
    printf("[模拟API] 正在将请求转发至内核...\n");
    Kernel_Bootstrap();
    printf("[模拟API] 内核引导成功。系统已初始化。\n");
    return 0; // 返回成功代码
}

// 显示一个模拟的消息框
SIM_API int Simulated_MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType) {
    // 参数未使用警告的抑制
    (void)hWnd;
    (void)uType;

    // [修改] 将英文输出替换为中文
    printf("[模拟API] 收到消息框（MessageBox）请求。\n");
    printf("[模拟API] 正在校验参数并转发至内核...\n");
    
    // 调用内核函数来执行实际的操作
    Kernel_HandleMessageRequest(lpText, lpCaption);
    
    printf("[模拟API] 内核已处理该消息请求。\n");
    return 0; // 假设总是成功
}
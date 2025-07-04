#include "simulated_api.h"
#include "simulated_kernel/simulated_kernel.h"
#include <stdio.h>

// 已有的API实现
int InitializeSystem(void) {
    printf("[SimAPI] Received request to initialize system.\n");
    printf("[SimAPI] Forwarding request to the kernel...\n");
    Kernel_Bootstrap();
    printf("[SimAPI] Kernel bootstrap successful. System is initialized.\n");
    return 0;
}

// 新增的API实现
SIM_API int Simulated_MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType) {
    // 参数未使用警告的抑制，这是一个好的编程习惯
    (void)hWnd;
    (void)uType;

    printf("[SimAPI] Received request for MessageBox.\n");
    printf("[SimAPI] Validating parameters and forwarding to kernel...\n");
    
    // 调用内核函数来执行实际的操作
    Kernel_HandleMessageRequest(lpText, lpCaption);
    
    printf("[SimAPI] Kernel has handled the message request.\n");
    return 0; // 假设总是成功
}
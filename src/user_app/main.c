#include "simulated_api/simulated_api.h"
#include <stdio.h>
#include <windows.h>

int main(void) {
    SetConsoleOutputCP(CP_UTF8);

    printf("[UserApp] Application starting...\n");
    
    printf("[UserApp] Calling high-level API to initialize system...\n");
    if (InitializeSystem() == 0) {
        printf("[UserApp] System initialization successful via API.\n\n");
    } else {
        printf("[UserApp] System initialization failed.\n");
        return 1;
    }
    
    // 调用我们新的API来显示一个消息框
    printf("[UserApp] Calling Simulated_MessageBoxA API...\n");
    Simulated_MessageBoxA(
        NULL, 
        "This is a test message from UserApp.", 
        "UserApp Message", 
        0
    );
    printf("[UserApp] Simulated_MessageBoxA API call finished.\n\n");

    // 再调用一次，展示其可复用性
    printf("[UserApp] Calling API again with different content...\n");
    Simulated_MessageBoxA(
        NULL,
        "探索第一性原理，洞见技术本质。",
        "学习心得",
        0
    );
    printf("[UserApp] Second API call finished.\n\n");

    printf("[UserApp] Application finished.\n");
    
    return 0;
}
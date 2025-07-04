#ifndef SIMULATED_API_H
#define SIMULATED_API_H

#ifdef SIMULATED_API_EXPORTS
    #define SIM_API __declspec(dllexport)
#else
    #define SIM_API __declspec(dllimport)
#endif

// 已有的API
SIM_API int InitializeSystem(void);

/**
 * @brief 显示一个模拟的消息框。
 * 
 * 这个API的签名模仿了Windows原生的MessageBoxA函数，以增强真实感。
 * @param hWnd 父窗口句柄，在我们的模拟中未使用，设为NULL。
 * @param lpText 消息文本。
 * @param lpCaption 消息标题。
 * @param uType 消息框类型，在我们的模拟中未使用，设为0。
 * @return int 总是返回0，代表成功。
 */
SIM_API int Simulated_MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType);

#endif // SIMULATED_API_H
#ifndef SIMULATED_KERNEL_H
#define SIMULATED_KERNEL_H

// 已有的内核引导函数
void Kernel_Bootstrap(void);

/**
 * @brief 内核层处理消息框请求的核心函数。
 * 
 * @param text 消息框要显示的主要文本。
 * @param caption 消息框的标题。
 */
void Kernel_HandleMessageRequest(const char* text, const char* caption);

#endif // SIMULATED_KERNEL_H
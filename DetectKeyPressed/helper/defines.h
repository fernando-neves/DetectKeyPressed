#ifndef HOTKEY_DEFINES_H
#define HOTKEY_DEFINES_H

/* THIS PROJECT INCLUDES */
#include <helper/includes.h>

#define CURRENT_VERSION "1.0.0"
#define THREAD_HANGS std::this_thread::sleep_for(std::chrono::milliseconds(UINT32_MAX))

#endif // !HOTKEY_DEFINES_H
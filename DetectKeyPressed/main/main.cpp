/* C++ INCLUDES */
#include <iostream>
#include <thread>

/* THIS PROJECT INCLUDES */
#include <helper/defines.h>
#include <hotkey/hotkey_manager.h>

void on_key_pressed(uint32_t process_id, uint32_t key_id, bool ctrl_pressed, bool shift_pressed) {
	std::cout << "\n PID: " << process_id << " - KEY:" << (char)key_id << " - ctrl: " << ctrl_pressed << " - shift: " << shift_pressed;
}

int main() {
	hotkey_manager::get()->initialize(on_key_pressed);

	THREAD_HANGS;
	return 0;
}
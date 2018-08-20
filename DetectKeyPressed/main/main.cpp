/* C++ INCLUDES */
#include <iostream>
#include <thread>

/* THIS PROJECT INCLUDES */
#include <helper/defines.h>
#include <hotkey/hotkey_manager.h>

void on_key_pressed(uint32_t key_id, bool ctrl_pressed, bool shift_pressed) {
	std::cout << "\n " << (char)key_id << " - ctrl: " << ctrl_pressed << " - shift: " << shift_pressed;
}

int main() {
	hotkey_manager::get();
	hotkey_manager::get()->set_callback(on_key_pressed);

	THREAD_HANGS;
	return 0;
}
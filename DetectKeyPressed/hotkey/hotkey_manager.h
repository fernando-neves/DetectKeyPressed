#ifndef HOTKEY_MANAGER_H
#define HOTKEY_MANAGER_H

/* THIS PROJECT INCLUDES */
#include <helper/defines.h>

class hotkey_manager {
public:
	hotkey_manager(
	) {
	}

	void initialize(
		std::function<void(uint32_t, uint32_t, bool, bool)> _on_callback
	) {
		static bool _started_thread = false;
		if (_started_thread)
			return;
		_started_thread = true;
		on_callback = _on_callback;

		std::thread(&hotkey_manager::runner_thread, this).detach();
	}

	void set_callback(
		std::function<void(uint32_t, uint32_t, bool, bool)> _on_callback
	) {
		on_callback = _on_callback;
	}

	static hotkey_manager* get(
	) {
		static hotkey_manager* singleton = nullptr;
		if (!singleton)
			singleton = new hotkey_manager();
		return singleton;
	}

private:
	bool is_ctrl_pressed(
	) {
		return 0 != (GetKeyState(VK_CONTROL) & 0x8000);
	}

	bool is_shift_pressed(
	) {
		return 0 != (GetKeyState(VK_SHIFT) & 0x8000);
	}
	
	uint32_t get_process_id(
	) {
		HWND hWnd = GetForegroundWindow();
		DWORD dwProcessId;
		GetWindowThreadProcessId(hWnd, &dwProcessId);
		return;
	}

	DWORD runner_thread(
	) {
		for (;;) {
			for (int key_id = 0x30; key_id <= 0x5A; key_id++) {
				if (VK_CONTROL == key_id || VK_SHIFT == key_id)
					continue;

				if (!GetAsyncKeyState(key_id))
					continue;

				if (!on_callback)
					continue;
				
				on_callback(get_process_id(), key_id, is_ctrl_pressed(), is_shift_pressed());
			}

			Sleep(120);
		}
	}
private:
	std::function<void(uint32_t, uint32_t, bool, bool)> on_callback;
};
#endif // !HOTKEY_MANAGER_H
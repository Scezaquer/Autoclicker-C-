#include <windows.h>
#include <iostream>
#include <chrono>

using namespace std;

int main() {
	INPUT inputMouse = { 0 };
	while (true) {

		if (GetKeyState('C') & 0x8000/*Check if high-order bit is set (1 << 15)*/) {
			inputMouse.type = INPUT_MOUSE;
			inputMouse.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

			SendInput(1, &inputMouse, sizeof(INPUT));
			::ZeroMemory(&inputMouse, sizeof(INPUT));

			inputMouse.type = INPUT_MOUSE;
			inputMouse.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			::SendInput(1, &inputMouse, sizeof(INPUT));
			::ZeroMemory(&inputMouse, sizeof(INPUT));
		}
	}
}
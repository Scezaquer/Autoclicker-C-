#include <windows.h>
#include <iostream>
#include <chrono>

using namespace std;

int main(){
	float cps;
	cout << "Nombre de cps : ";
	cin >> cps;
	double tpc = 1.0 / cps;
	std::chrono::steady_clock::time_point debut = std::chrono::steady_clock::now();
	std::chrono::duration<double> work_time;
	INPUT inputMouse = { 0 };
	while (true) {
	
		work_time = std::chrono::steady_clock::now() - debut;
		if (GetKeyState('C') & 0x8000/*Check if high-order bit is set (1 << 15)*/ and work_time.count() >= tpc){
			debut = std::chrono::steady_clock::now();
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
#include <iostream>
#include <Windows.h>
#include <thread>

using namespace std;

bool oofs, clState = true;
int slep, x, y;

void check() {
	while (true) {
		if (GetAsyncKeyState(VK_DIVIDE)) exit(0);
		if (GetAsyncKeyState(VK_MULTIPLY) & 0x0001) clState = !clState;
	}
}

int click() {
	POINT pos;
	if (!GetCursorPos(&pos)) return 1;

	x = pos.x;
	y = pos.y;;

	while (true) {
		if (clState) {
			if (oofs) SetCursorPos(x, y);
			mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

			Sleep(slep);
		}
	}

	return 0;
}

int main() {
	cin >> oofs >> slep;

	thread cl(click);
	thread ch(check);

	ch.join(); cl.join();

	return 0;
}
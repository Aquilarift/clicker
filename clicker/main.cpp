#include <iostream>
#include <Windows.h>
#include <thread>

using namespace std;


bool oofs, clState = true;
int slep, x, y;

void check() {
	while (clState) {
		if (GetAsyncKeyState(VK_MULTIPLY)) {
			clState = false;
		}
	}
}

int click() {
	POINT* pos = new POINT();
	if (!GetCursorPos(pos)) { delete pos; return 1; }

	x = pos->x;
	y = pos->y;

	while (clState) {
		if (oofs) SetCursorPos(x, y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

		Sleep(slep);
	}

	delete pos;
	return 0;
}

int main() {
	cin >> oofs >> slep;

	thread cl(click);
	thread ch(check);

	ch.join(); cl.join();

	return 0;
}
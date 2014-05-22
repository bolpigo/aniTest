/**
* just a test for thread on window 7
* author @ bolpigo
*/
#include <iostream>
#include <windows.h>
using namespace std;
HANDLE _thread;
HANDLE _mainThread;
const int loop=50;
DWORD WINAPT run(LPVOID lp) {
	for(int i = 0; i < loop; ++i) {
		WaitForSingleObject(_thread, INTINITE);
		ResetEvent(_mainThread);
		printf("\n\t\t~thread start~\n");
		Sleep(5);
		printf("\n\t\t~thread exit~\n");
		SetEvent(_mainThread);
	}
}
void mainRun() {
	for(int i = 0; i < loop; ++i) {
		WaitSingleObject(_mainThread, INTINITE);
		ResetEvent(_thread);
		printf("\n\t\t~main thread start~\n");
		Sleep(5);
		printf("\n\t\t~main thread exit~\n");
	}
}
int main() {
	_thread = CreateEvent(NULL, false, true, NULL);
	_mainThread = CreateEvent(NULL, false, false, NULL);
	ResetEvent(_mainThread);
	HANDLE hThread = (HANDLE)CreateThread(NULL, 0, run, NULL, 0, NULL);
	mainRun();
	WaitForMultipleObjects(1, &hThread, TRUE, INTITE);
	cout<<"Press any key to quie...\n";
	getchar();
	CloseHandle(_thread);
	CloseHandle(hThread);
	CloseHandle(_mainThread);
	return 0;
}

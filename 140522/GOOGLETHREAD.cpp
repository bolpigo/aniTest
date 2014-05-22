#include <iostream>
#include <windows.h>
using namespace std;
const int N = 4;
HANDLE _thread[N];
int _cur = 0;
DWORD WINAPI run(void *p) {
	int i = (int)p;
	char c = 'A' + i;
	WaitForSingleObject(_thread[i], INFINITE);
	printf("the thread is %c\n", c);
	ResetEvent(_thread[_cur]);
	_cur = (_cur+1)%N;
	SetEvent(_thread[_cur]);
	return 0;
}
int main() {
	for(int i = 0; i < N; ++i) {
		_thread[i] = CreateEvent(NULL, false, false, NULL);
	}
	HANDLE hThread[N];
	for(int i = 0; i < N; ++i) {
		_cur = i;
		printf("\n\t\t%dtimes start run\n",i);
		SetEvent(_thread[_cur]);
		for(int j = 0; j < N; ++j) {
			hThread[j] = (HANDLE) CreateThread(NULL, 0, run, (void *)j, NULL);
		}
		WaitForMultipleObjects(N, hThread, TRUE, INFINITE);
		for(int j = 0; j < N; ++j) {
			ResetEvent(_thread[j]);
			CloseHandle(_thread[j]);
		}
		printf("\n\t\t%dtimes end\n",i);
	}
	cout << "press any key to quit..."<<endl;
	getchar();
	CloseHandle(*_thread);
	return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
const char *filename = "example.txt";
int main() {
	char *buffer;
	long size;
	ifstream file(filename, ios::binary);
	file.seekg(0, ios::end);
	size = file.tellg();
	file.seekg(0, ios::beg);
	buffer = new char[size+1];
	file.read(buffer, size);
	buffer[size]='\0';
	file.close();
	cout<<"the complete file is in a buffer";
	char *p=buffer;
	while(*p) {
		cout<<*p++;
	}
	delete[] buffer;
	cout<<"press any ket to quit..."<<endl;
	getchar();
	return 0;
}

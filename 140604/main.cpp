#include "StatDir.h"
#include "CPP_H_LineCount.h"
int main() {
	char buf[256];
	char v;
	printf("������Ҫͳ�Ƶ�Ŀ¼��:");
	gets(buf);
	printf("ʹ��Ĭ��Ŀ¼��Y,N");
	cin>>v;
	StatDir statdir;
	if(v=='N') {
		if(!statdir.SetInitDir(buf)) {
			puts("Ŀ¼������");
			return 0;
		}
	} else {
		if(!statdir.SetInitDir()) {
			puts("Ŀ¼������");
			return 0;
		}
	}
	vector<string> file_vec = statdir.BeginBrowseFileNames("*.*");
	CPP_H_LineCount cpplinecount;
	for(vector<string>::const_iterator it = file_vec.begin(); it < file_vec.end(); ++it) {
		//cout << *it << endl;
		cpplinecount.CountLines((*it).c_str());
	}
	//printf("wen������: %d\n",file_vec.size());
	cout << ".cpp������:"<<cpplinecount.GetCPPLines()<<endl;
	cout << ".h������:"<<cpplinecount.GetHLines()<<endl;
	cout << ".c������:"<<cpplinecount.GetCLines()<<endl;
	cout << "����������"<<cpplinecount.GetCPPLines()+cpplinecount.GetHLines()+cpplinecount.GetCLines()<<endl;
	cout<<"press any key to quit..."<<endl;
	getchar();
	system("pause");
	return 0;
}
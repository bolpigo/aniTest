#include "StatDir.h"
#include "CPP_H_LineCount.h"
int main() {
	char buf[256];
	char v;
	printf("请输入要统计的目录名:");
	gets(buf);
	printf("使用默认目录？Y,N");
	cin>>v;
	StatDir statdir;
	if(v=='N') {
		if(!statdir.SetInitDir(buf)) {
			puts("目录不存在");
			return 0;
		}
	} else {
		if(!statdir.SetInitDir()) {
			puts("目录不存在");
			return 0;
		}
	}
	vector<string> file_vec = statdir.BeginBrowseFileNames("*.*");
	CPP_H_LineCount cpplinecount;
	for(vector<string>::const_iterator it = file_vec.begin(); it < file_vec.end(); ++it) {
		//cout << *it << endl;
		cpplinecount.CountLines((*it).c_str());
	}
	//printf("wen件总数: %d\n",file_vec.size());
	cout << ".cpp总行数:"<<cpplinecount.GetCPPLines()<<endl;
	cout << ".h总行数:"<<cpplinecount.GetHLines()<<endl;
	cout << ".c总行数:"<<cpplinecount.GetCLines()<<endl;
	cout << "代码总行数"<<cpplinecount.GetCPPLines()+cpplinecount.GetHLines()+cpplinecount.GetCLines()<<endl;
	cout<<"press any key to quit..."<<endl;
	getchar();
	system("pause");
	return 0;
}
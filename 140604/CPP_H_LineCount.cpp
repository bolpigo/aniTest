#include "CPP_H_LineCount.h"

char *strrstr(const char *s, int c)
{
    const char ch = c;
    const char *sc;

    for (sc = NULL; ; ++s)
    {
        if (*s == ch)
            sc = s;
        if (*s == '\0')
            return ((char *) sc);
    }

   // assert(0);
    return NULL;
}

bool CPP_H_LineCount::ProcessFile(const char *filename) {
	int len = strlen(filename);
	const char *pos = strrstr(filename, '.');
	if(!pos) return false;
	++pos;
	bool flag1 = strcmp(pos,"cpp") == 0; 
	bool flag2 = strcmp(pos,"h") == 0; 
	bool flag3 = strcmp(pos,"c") == 0; 
	if(flag1 || flag2 || flag3) {
		ifstream file(filename);
		string line;
		while(file && getline(file, line)) {
			//cout<<line<<endl;
			if(flag1) {
				++m_n_cpplines;
			} else if(flag2) {
				++m_n_hlines;
			} else {
				++m_n_clines;
			}
		}
		file.close();
	}
	return CBrowseDir::ProcessFile(filename);
}

void CPP_H_LineCount::CountLines(const char *filename) {
	ProcessFile(filename);
}

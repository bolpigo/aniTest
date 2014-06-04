#ifndef CPP_H_LINECOUNT_H
#define CPP_H_LINECOUNT_H
#include "BrowseAllFile.h"
class CPP_H_LineCount:public CBrowseDir {
private:
	int m_n_cpplines;
	int m_n_hlines;
	int m_n_clines;
	virtual bool ProcessFile(const char *filename);
public:
	CPP_H_LineCount():m_n_cpplines(0),m_n_hlines(0),m_n_clines(0){}
	int GetCPPLines() {return m_n_cpplines; }
	int GetHLines() {return m_n_hlines;}
	int GetCLines() {return m_n_clines;}
	void CountLines(const char *filename);
};
#endif

#ifndef STATDIR_H
#define STATDIR_H

#include "BrowseAllFile.h"

class StatDir:public CBrowseDir {
private:
	int m_nFileCount;
	int m_nSubdirCount;
protected:
	virtual bool ProcessFile(const char *filename) {
		++m_nFileCount;
		return CBrowseDir::ProcessFile(filename);
	}
	virtual void ProcessDir(const char *currentdir, const char *parentdir) {
		++m_nSubdirCount;
		CBrowseDir::ProcessDir(currentdir, parentdir);
	}
public:
	StatDir():m_nFileCount(0),m_nSubdirCount(0){}
	int GetFileCount() { return m_nFileCount;}
	int GetSubdirCount() { return m_nSubdirCount-1;}
};
#endif
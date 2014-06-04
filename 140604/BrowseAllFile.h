#ifndef BROWSEALLFLL_H
#define BROWSEALLFLL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "direct.h"  
#include "io.h"
using namespace std;

class CBrowseDir {
private:
	string path;
public:
	//vector<string> files;
	bool SetInitDir(const string dir="F:\\software\\xpns\\src\\") {
		path = dir;
		if(_chdir(dir.c_str()) != 0)
			return false;
		if(dir[dir.size()-1] != '\\')
			path+='\\';
		return true;
	}
	bool BeginBrowse(const char *filespec);
	vector<string> BeginBrowseFileNames(const char *filespec);
protected:
	bool BrowseDir(const char *dir, const char *filespec);
	vector<string> GetDirFileNames(const char *dir, const char *filespec);
	virtual bool ProcessFile(const char *filename) { return true ;}
	virtual void ProcessDir(const char *currentdir, const char *parentdir){}
};
#endif
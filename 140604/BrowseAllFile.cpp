/***************************************/
//
//遍历某一目录下的所有文件
//
/***************************************/

#include "BrowseAllFile.h"

vector<string> CBrowseDir::BeginBrowseFileNames(const char *filespec) {
	ProcessDir(path.c_str(),NULL);
	return GetDirFileNames(path.c_str(), filespec);
}
bool CBrowseDir::BeginBrowse(const char *filespec) {
	ProcessDir(path.c_str(),NULL);
	return BrowseDir(path.c_str(),filespec);
}
bool CBrowseDir::BrowseDir(const char *dir, const char *filespec) {
	_chdir(dir);
	long hFile;
	_finddata_t fileinfo;
	if((hFile = _findfirst(filespec, &fileinfo)) != -1) {
		do {
			if(!(fileinfo.attrib & _A_SUBDIR)) {
				char filename[_MAX_PATH];
				strcpy(filename,dir);
				strcat(filename,fileinfo.name);
				cout << filename <<endl;
				if(!ProcessFile(filename))
					return false;
			}
		} while(_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	_chdir(dir);
	if((hFile=_findfirst("*.*", &fileinfo)) != -1) {
		do {
			if((fileinfo.attrib & _A_SUBDIR)) {
				if(strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0) {
					char subdir[_MAX_PATH];
					strcpy(subdir,dir);
					strcat(subdir,"\\");
					ProcessDir(subdir,dir);
					if(!BrowseDir(subdir,filespec))
						return false;
				}
			}
		} while(_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	return true;
}
vector<string> CBrowseDir::GetDirFileNames(const char *dir, const char *filespec) {
	_chdir(dir);
	vector<string> filename_vec;
	filename_vec.clear();
	long hFile;
	_finddata_t fileinfo;
	if((hFile = _findfirst(filespec, &fileinfo)) != -1) {
		do {
			if(!(fileinfo.attrib & _A_SUBDIR)) {
				char filename[_MAX_PATH];
				strcpy(filename,dir);
				strcat(filename,fileinfo.name);
				filename_vec.push_back(filename);
			}
		} while(_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	_chdir(dir);
	if((hFile = _findfirst("*.*", &fileinfo)) != -1) {
		do {
			if((fileinfo.attrib & _A_SUBDIR)) {
				if(strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
					char subdir[_MAX_PATH];
					strcpy(subdir,dir);
					strcat(subdir,fileinfo.name);
					strcat(subdir,"\\");
					vector<string> tmp = GetDirFileNames(subdir,filespec);
						for(vector<string>::iterator it = tmp.begin(); it < tmp.end(); ++it) {
							filename_vec.push_back(*it);
						}
				}
			}
		} while(_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	return filename_vec;
}
void BFS(const string &url) {
	char *response;
	int bytes;
	if(!GetHttpResponse(url, response, bytes)) {
		cout << "The url is wrong~ ignore"<<endl;
		return;
	}
	string httpResponse=response;
	free(response);
	string filename = ToFileName(url);
	ofstream ofile("./html/"+filename);
	if(ofile.is_open()) {
		ofile << httpResponse<<endl;
		ofile.close();
	}
	vector<string> imgurls;
	HTMLParse(httpResponse, imageurls, url);
	DownLoadImg(imgurls, url);
}
bool GetHttpResponse(const string &url, char *&response, int &bytesRead) {
	string host,resource;
	if(!ParseURL(url, host, resource)) {
		cout<<"Can't parse the url"<<endl;
		return false;
	}
	struct hostent *hp = gethostbyname(host.c_str());
	if(hp == NULL) {
		cout << "Can't find host address"<<endl;
		return false;
	}
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sock == -1 || sock == -2) {
		cout << "Can't create sock"<<endl;
		return false;
	}
	SOCKADDR_IN sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(80);
	memcpy(&sa.sin_addr, hp->h_addr,4);
	if(0 != connect(sock, (SOCKADDR*)&sa, sizeof(a))) {
		cout << "Can't connect:"<<url<<endl;
		closesocket(sock);
		return false;
	}
	string request = "Get" + resource + "HTTP/1.1\r\nHost:"+host+"\r\nConnection:Close\r\n\r\n";
	if(SOCKET_ERROR==send(sock,request,c_str(), request.size(), 0)) {
		cout << "send error" <<endl;
		closesocket(sock);
		return false;
	}
	int m_nContentLength = DEFAULT_PAGE_BUF_SIZE;
	char *pageBuf = (char *)malloc(m_nContentLength);
	memset(pageBuf,0,m_nContentLength);
	bytesRead = 0;
	int ret = 1;
	cout << "Read: ";
	while(ret > 0) {
		ret = recv(sock, pageBuf+bytesRead, m_nContentLength - bytesRead, 0);
		if(ret > 0) {
			bytesRead += ret;
		}
		if(m_nContentLength - bytesRead < 100) {
			count << "\nRealloc memory"<<endl;
			m_nContentLength *= 2;
			pageBuf = (char*)realloc(pageBuf, m_nContentLength);
		}
		cout << ret <<" " ;
	}
	cout<<endl;
	pageBuf[bytesRead] = '\0';
	response = pageBuf;
	closesocket(sock);
	return true;
}
bool ParseURL(const string &url, string &host, string &resource) {
	const char *pos = strstr(url.c_str(),"http://");
	if(pos == NULL) pos=url.c_str();
	else pos += strlen("http://");
	if(strstr(pos,"/" == 0)) return false;
	char pHost[100];
	char pResource[200];
	sscanf(pos,"%[^/]%s",pHost,  pResource);
	host = pHost;
	resource = pResource;
	return true;
}
void HTMLParse( string &htmlResponse, vector<string> &imgurls, const string &host){
	const char *p = htmlResponse.c_str();
	char *tag="href=\"";
	const char *pos = strstr(p,tag);
	ofstream *ofile(url.txt, ios::app);
	while(pos) {
		pos += strlen(tag);
		const char *nextQ = strstr(pos,"\"");
		if(nextQ) {
			char *url = new char [nextQ-pos+1];
			sscanf(pos, "%[^\"]",url);
			string surl = url;
			if(visitedUrl.find(sur1) == visitedUrl.end()) {
				visitedUrl.insert(sur1);
				ofile << surl << endl;
				hrefUrl.push(sur1);
			}
			pos = strstr(pos,tag);
			delete[] url;
		}
	}
	ofile << endl << endl;
	ofile.close();
	tag="<img";
	const char *att1= "src=\"";
	const char *att2="lazy-src=\"";
}

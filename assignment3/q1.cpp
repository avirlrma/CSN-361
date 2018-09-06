#include <iostream>

using namespace std;

/*string addlength()*/


int main(int argc, char const *argv[]){
	string s;
	getline(cin,s);
	string header = s.substr(0,20);
	string payload = s.substr(20,s.length()-20);
	int mtu;
	cin>>mtu;
	int nfu =((mtu-20)/8);
	int index = 0 ;
	while((index)<=payload.length()){
		string cur_data = payload.substr(index,nfu*8);
		string header_frag = header;
		index+=nfu*8;
	}
	return 0;
}

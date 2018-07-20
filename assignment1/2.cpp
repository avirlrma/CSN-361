#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{	if(argc<4){
		cout<<"give memore";
		return -1;
	}
	else{
		int x = stoi(argv[1]);
		int y = stoi(argv[3]);
		string ch = argv[2];
		//cout<<ch;
		if(ch.compare("+")==0){
			cout<<x+y<<endl;
		}
		else if(ch.compare("-")==0){
			cout<<x-y<<endl;
		}
		else if(ch.compare("*")==0){
			cout<<x*y<<endl;
		}
		else if(ch.compare("/")==0){
			if(y==0){
				cerr<<"eroor ";
			}
			else{
				cout<<x/y<<endl;	
			}
		}
	}
	return 0;
}

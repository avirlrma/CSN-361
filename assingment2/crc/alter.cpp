#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{	string encoded_message;
	getline(cin,encoded_message);
	string poly;
	getline(cin,poly);
	int bit = stoi(argv[argc-1]);
	string tempered_message = "";
	for(int i=0;i<encoded_message.length();i++){
		if(i==bit){
			if(encoded_message[i]=='0')
				tempered_message +='1';
			else
				tempered_message +='0';

		}
		tempered_message += encoded_message[i];
	}
	cout<<tempered_message<<endl;
	cout<<poly<<endl;
	return 0;
}
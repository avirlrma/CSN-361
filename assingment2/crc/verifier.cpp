#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string mod2div(string,string);
string xoro(string a,string b);


int main(int argc, char const *argv[])
{	string encoded_message;
	getline(cin,encoded_message);
	string poly;
	getline(cin,poly);
	int rem = stoi(mod2div(encoded_message,poly));
	if(rem==0){
		cout<<"Correct Info Transmitted "<<endl;
	}
	else{
		cout<<"Wrong Info "<<endl;
	}
	return 0;
}


string xoro(string a,string b){
	string result = "";
	for(int i=1;i<b.length();i++){
		if(a[i]==b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}

string mod2div(string divident,string divisor){
	int k =  divisor.length();
	string s = divident.substr(0,k);
	while(k<divident.length()){
		if(s[0]=='1'){
			s = xoro(divisor,s) + divident[k];
		}
		else{
			string tmp = "";
			for(int i=0;i<s.length();i++)
				tmp+="0";
			s = xoro(tmp, s) + divident[k];
		}
		k++;
	}
	if(s[0]=='1'){
			s = xoro(divisor,s) ;
		}
		else{
			string tmp = "";
			for(int i=0;i<s.length();i++)
				tmp+="0";
			s = xoro(tmp, s) ;
		}
		return s;
}

// g++ generator.cpp -o generator
// g++ verifier.cpp -o verifier
// ./generator | ./verifier
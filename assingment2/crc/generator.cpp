#include <iostream>

using namespace std;

string mod2div(string,string);
string xoro(string a,string b);

int main(int argc, char const *argv[])
{	string message,polynomial;
	getline(cin,message);
	getline(cin,polynomial);
	char zero = '0' ;
	string kzeroes = ""; 
	int k = polynomial.length();
	for(int i=0;i<k-1;i++){
		kzeroes+=zero;
	}
	string temp_message = message + kzeroes;
	//cout<<temp_message;
	string encoded_message = message+mod2div(temp_message,polynomial);
	cout<<encoded_message<<endl;
	cout<<polynomial;
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
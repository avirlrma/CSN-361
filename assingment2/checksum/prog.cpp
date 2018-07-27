#include <iostream>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

const char* hex_char_to_bin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

std::string hex_str_to_bin_str(const std::string& hex)
{
    // TODO use a loop from <algorithm> or smth
    std::string bin;
    for(unsigned i = 0; i != hex.length(); ++i)
       bin += hex_char_to_bin(hex[i]);
    return bin;
}

string addBinary(string a, string b)
{
    string result = ""; 
    int s = 0;      
 
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);
 
        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;
 
        // Compute carry
        s /= 2;
 
        // Move to next digits
        i--; j--;
    }
    if(s==1){
    	return addBinary(result,"1");
    }
    return result;
}

int main(int argc, char const *argv[])
{	vector<string> headers;				// destination thing
	string s = "4500 003c 1c46 4000 4006 0000 ac10 0a63 ac10 0a0c";
	//getline(cin,s);
	stringstream ss(s);
	string word;
	while(ss>>word)
		headers.push_back(word);
	string sum = "0000000000000000";
	for(int i=0;i<headers.size();i++){
		sum  = addBinary(sum,hex_str_to_bin_str(headers[i]));
	}
	cout<<"bit sums is "<<sum<<endl;
	string ans = "";
	for(int i=0;i<sum.length();i++){
		if(sum[i]=='0')
			ans+="1";
		else
			ans+="0";
	}
	cout<<" the checksum is "<<ans<<endl;
	return 0;
}

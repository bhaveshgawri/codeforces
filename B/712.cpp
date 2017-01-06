#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
	string s;
	int u=0,d=0,l=0,r=0;
	cin>>s;
	if (s.length()%2 != 0){
		cout<<"-1";
		return 0;
	}
	else{
		int len=s.length();
		for (int i=0;i<len;i++){
			if (s[i]=='U'){u++;}
			else if (s[i]=='D'){d++;}
			else if (s[i]=='R'){r++;}
			else if (s[i]=='L'){l++;}
		}
		cout<<(abs(u-d)+abs(r-l))/2;
	}	
}

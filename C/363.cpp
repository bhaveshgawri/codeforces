#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int l = s.length();
	string one = "";
	int flag = 0;
	for (int i=0;i<l;i++){
		flag = 0;
		if (s[i]==s[i+1] && s[i+1]==s[i+2]){
			while(s[i]==s[i+1])i++;
			flag = 1;
		}
		one+=s[i];
		if (flag==1)one+=s[i];
	}
	l = one.length();
	one += "ABCDE";
	string two = "";
	for (int i=0; i<l; i++){
		if (one[i]==one[i+1] && one[i+2]==one[i+3]){
			two += one[i];
			two += one[i];
			two += one[i+2];
			i+=3;
			continue;
		}
		two += one[i];
	}
	cout<<two<<endl;
}

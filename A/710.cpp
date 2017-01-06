#include <iostream>
#include <string>

using namespace std;
int main(){
	string s;
	cin>>s;
	if(s[0]>='b' && s[0]<='g' && s[1]<='7' && s[1]>='2'){
		cout<<"8"<<endl;
	}
	else if(((s[0]=='a' || s[0]=='h') && s[1]>='2' && s[1]<='7') || ((s[1]=='1' || s[1]=='8') && s[0]>='b' && s[0]<='g')) cout<<"5"<<endl;
	else cout<<"3"<<endl;
}

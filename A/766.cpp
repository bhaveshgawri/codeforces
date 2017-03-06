#include <iostream>
#include <string>

using namespace std;

int main(){
	string s,q;
	cin>>s>>q;
	int ls = s.length(), lq = q.length();
	if (s==q){
		cout<<-1;
		return 0;
	}
	if (ls!=lq){
		if (ls>lq){
			cout<<ls;
			return 0;
		}
		else{
			cout<<lq;
			return 0;
		}
	}
	else if (ls==lq && s!=q){
		cout<<ls;
		return 0;
	}
}
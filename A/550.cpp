#include <iostream>
#include <string>

#define INF 9999999

using namespace std;

int main(){
	string s;
	cin>>s;
	int l = s.size();
	int pos = s.find("AB");
	if (pos==string::npos)
		cout<<"NO";
	else{
		int pos_=s.find("BA",pos+2);
		if (pos_!=string::npos){
			cout<<"YES";
		}
		else{
			int pos__=s.rfind("AB");
			//cout<<pos__;
			int __pos__ = -1*INF;
			if (pos__>1)
				__pos__=s.rfind("BA",pos__-2);
			//cout<<endl<<__pos__;
			if(pos__!=string::npos && __pos__!=-1*INF && __pos__!=string::npos)
				cout<<"YES";
			else
				cout<<"NO";
		}
	}
}
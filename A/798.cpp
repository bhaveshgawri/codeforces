#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin>>s;
	int count = 0;
	for (int i=0, l= s.length();i<l/2;i++){
		if (s[i]!=s[l-i-1]){
			count++;
			//cout<<count<<endl;
			//cout<<s[i]<<" "<<s[l-i-1]<<endl;
			
		}
		if (count>1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if (s.length()%2==1){
		cout<<"YES"<<endl;
	}
	else if (count==1 && s.length()%2==0){
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
}
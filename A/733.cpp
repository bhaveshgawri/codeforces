#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin>>s;
	int l = s.length();
	int max = 0;
	int count=0;
	for (int i=0;i<l;i++){
		if (s[i]!='A'&&s[i]!='E'&&s[i]!='O'&&s[i]!='I'&&s[i]!='U'&&s[i]!='Y'){
			//cout<<s[i];
			count++;
			if (max<count){
				max=count;
				//cout<<count;
			}
		}
		else count=0;
	}
	cout<<max+1;
}
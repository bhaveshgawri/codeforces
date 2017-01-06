#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string s;
	cin>>s;
	vector<int> v;
	int l=s.size();
	for (int i=0;i<l;i++){
		if(s[i]=='a')	
			v.push_back(i);
	}	
	int flag=0;
	int w=v.size();
	
	if(w==l) s.back() = 'z';
	
	else if (w==0){
		for (int i=0;i<l;i++){
			s[i]-=1;
		}
	}
	else if (w==1){
		if (v[0]==0){
			for (int i=1;i<l;i++){
				s[i]-=1;
			}
		}
		else {
			for (int i=0;i<v[0];i++){
				s[i]-=1;
			}
		}
	}
	else {
		//cout<<1;
		for (int i=0;i<l;i++){
			if (s[i]!='a' && flag==0){
				int j=i;
				while (s[j]!='a'){
					//cout<<1;
					s[j]-=1;
					j++;
					flag=1;
				}
			}
		}
	}
	cout<<s;
}

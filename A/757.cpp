#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string s;
	cin>>s;
	vector<int>v(7);
	for (int i=0,l=s.size();i<l;i++){
		if (s[i]=='B')v[0]++;
		else if (s[i]=='b')v[1]++;
		else if (s[i]=='a')v[2]++;
		else if (s[i]=='u')v[3]++;
		else if (s[i]=='l')v[4]++;
		else if (s[i]=='s')v[5]++;
		else if (s[i]=='r')v[6]++;		
	}
	v[2]/=2;
	v[3]/=2;
	int min=v[0];
	for (int i=1,l=v.size();i<l;i++){
		if (v[i]<min)
			min=v[i];
	}
	cout<<min;
}
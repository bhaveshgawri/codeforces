#include <iostream>
#include <string>

using namespace std;

int main(){
	string x, y, z;
	cin>>x>>z;
	for (int i=0, l=x.length();i<l;i++){
		if (z[i]==x[i]){
			y.push_back(z[i]);
		}
		else if (z[i]<x[i]){
			y.push_back(z[i]);
		}
		else{
			y.push_back('*');
		}
	}
	//cout<<y<<endl;
	auto found = y.find('*');
	if (found!=string::npos)
		cout<<-1<<endl;
	else
		cout<<y<<endl;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<string> v(3);
	for (int i=0;i<3;i++){
		cin>>v[i];
	}
	int a = stoi(v[0]);
	int b = stoi(v[1]);
	int c = stoi(v[2]);
	int count=0;
	for(int i=1;i<=c;i++){
		if (i%a==0 && i%b==0){
			count++;
		}	
	}
	cout<<count;
}
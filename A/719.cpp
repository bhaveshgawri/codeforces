#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	if (n==1 && v[n-1]==15) {cout<<"DOWN";return 0;}
	if (n==1 && v[n-1]==0)  {cout<<"UP";return 0;}
	if (n==1 || v[n-2]==v[n-1]) {cout<<"-1";return 0;}
	if (v[n-2] > v[n-1] && v[n-1]!=0){ cout<<"DOWN";return 0;}
	if (v[n-2] > v[n-1] && v[n-1]==0){ cout<<"UP";return 0;}
	if (v[n-2] < v[n-1] && v[n-1]!=15){ cout<<"UP";return 0;}
	if (v[n-2] < v[n-1] && v[n-1]==15){cout<<"DOWN";return 0;}
	
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int min =  v[0];
	int max = v[n-1];
	int count = 0;
	for (int i=0;i<n;i++){
		if (v[i]!=min && v[i]!=max){
			count++;
		}
	}
	cout<<count;
}
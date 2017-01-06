#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin >> v[i];
	}
	int count=1,max=1;
	for(int i=0;i<n-1;i++){
		if (v[i+1]>=v[i])count++;
		if (max < count)max=count;
		if (v[i+1]<v[i])count=1;
	}
	cout<<max;
}
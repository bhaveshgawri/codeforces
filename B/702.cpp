#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,count=0;
	cin>>n;
	vector<int> v(n);
	long long int a[] ={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456, 536870912, 1073741824, 2147483648};
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	for (int  i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (binary_search(a,a+31,v[i]+v[j]))count++;
		}
	}
	cout<<count;
}

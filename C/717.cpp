#include<iostream>
#include<algorithm>

using namespace std;



int main(){
	int n;
	long long int sum=0;
	cin>>n;
	long long v[100001];
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v,v+n);
	for(int i=0;i<n;i++){
		sum+=(v[i]*v[n-i-1]);
		sum%=10007;
	}
	cout<<sum;
	return 0;
}

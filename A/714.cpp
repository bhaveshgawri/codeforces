#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long int ans,k;
	vector<long long int> v(4),c(4);
	for (int i=0;i<4;i++){
		cin>>v[i];
		c[i]=v[i];
	}	
	cin>>k;
	sort(v.begin(),v.end());
	ans=v[2]-v[1]+1;
	if (c[1]< c[2] || c[3] < c[0]) {ans =0;cout<<ans;}
	else if (k<=v[2] && k>=v[1]) cout<<ans-1;
	else cout<<ans;
}

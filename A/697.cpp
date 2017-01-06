#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t,s,x;
	cin>>t>>s>>x;
	vector<long long int> v;
	v[0]=t;
	for (long long int i=1;i<x;i+=2){
		v[i]=t+(i*s);
		v[i+1]=t+(i*s)+1;
		cout<<v[i]<<" "<<v[i+1]<<endl;
	}
	if (is_sorted(v.begin(),v.end())){;}
	else 	sort(v.begin(),v.end());
	if (binary_search(v.begin(),v.end(),x)){cout<<"YES";}
	else cout<<"NO";
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	vector<set<char>> vs(m);
	for (int i=0;i<n;i++){
		string s;
		cin>>s;
		for (int j=0;j<m;j++){
			vs[j].insert(s[j]);
		}
	}
	ll ans = 1;
	for (auto i: vs){
		ans *= (ll)i.size();
		ans %= 1000000007;
	}
	cout<<ans<<endl;
}
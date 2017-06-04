#include <bits/stdc++.h>

#define pb push_back
#define ll long long int
using namespace std;

vector<vector<int> > H(100004);
vector<int> deg(100004);
vector<int> visited(100004, 0);
vector<ll> tail(100004, 1);

int main(){
	int n, m, p, q;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>p>>q;
		H[p].pb(q);
		H[q].pb(p);
	}
	for (int i=1;i<=n;i++){
		deg[i] = H[i].size();
	}
	for (int i=1;i<=n;i++){
		tail[i]=1;
		for (int j: H[i]){
			if (j<i){
				tail[i]=max(tail[i], tail[j]+1);
			}
		}
	}
	for (int i=1;i<=n;i++){
		tail[i]*=deg[i];
	}
	cout<<*max_element(tail.begin(), tail.end())<<endl;
}
#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

vector<vector<pair<int, int> > >C(100004);
vector<int> candidates;
vector<int> visited(5004, 0);

int dfs(){
	
}

int main(){
	int n, p, q, t;
	cin>>n;
	for (int i=0;i<n-1;i++){
		cin>>p>>q>>t;
		C[p].pb({q, t});
		C[q].pb({p, t});
	}
	dfs();
	cout<<candidates.size()<<endl;
	for (auto i: candidates)
		cout<<i<<" ";
	cout<<endl;
}
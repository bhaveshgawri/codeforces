#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<set<int> >L(104);
vector<int> deg(104);
vector<int>deg1;


int main(){
	int n, m, p, q;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>p>>q;
		L[p].insert(q);
		L[q].insert(p);
	}
	for (int i=1;i<=n;i++){
		deg[i]=L[i].size();
	}
	int count=0;
	for (int i=1;i<=n;i++){
		if (deg[i]==1)
			count++;
	}
	int ans=0;
	int ct=0;
	while(count){
		ans++;
		for (int i=1;i<=n;i++){
			if (deg[i]==1){
				deg1.pb(i);
			}
		}
		for (int i: deg1){
			L[i].clear();
		}
		for (int j: deg1){
			for (int i=1;i<=n;i++){
				L[i].erase(j);
			}
		}
		for (int i=1;i<=n;i++){
			deg[i]=L[i].size();
		}
		count=0;
		for (int i=1;i<=n;i++){
			if (deg[i]==1)
				count++;
		}
		deg1.clear();
	}
	cout<<ans;
}
#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int> > >G(100005);
vector<int> bakeries;
vector<int> bakery_index(100005, 0);

int main(){
	int n, m, k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int p, q, l;
		cin>>p>>q>>l;
		G[p].push_back({q, l});
		G[q].push_back({p, l});
	}
	for (int i=0;i<k;i++){
		int b;
		cin>>b;
		bakeries.push_back(b);
		bakery_index[b]=1;
	}
	cout<<endl;
	int ans = INT_MAX;
	for (int i: bakeries){
		for (auto it=G[i].begin();it!=G[i].end();++it){
			if (bakery_index[(*it).first]==0)
				ans = min(ans, (*it).second);
		}
	}
	if (ans==INT_MAX)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}
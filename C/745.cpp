#include <bits/stdc++.h>

#define pb push_back

using namespace std;

vector<int> spec;
vector<int> spec_companions(1004, 0);
vector<int> visited(1004, 0);
vector<vector<int> > H(1004);

int dfs1(int node, int size){
	if (!visited[node]){
		visited[node]=1;
		size++;
		for (int i: H[node]){
			size = dfs1(i, size);
		}
	}
	return size;
}

int main(){
	int n, m, k, p, q, ans=0;
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++){
		cin>>p;
		spec.pb(p);
	}
	for (int i=0;i<m;i++){
		cin>>p>>q;
		H[p].pb(q);
		H[q].pb(p);
	}
	for (int i: spec){
		spec_companions[i] = dfs1(i, 0);
	}
	for (int i: spec){
		int x = spec_companions[i];
		ans+=((x*(x-1))/2);
	}
	int normal_count_vertices=0;
	for (int i=1;i<=n;i++){
		if (visited[i]==0){
			normal_count_vertices++;
		}
	}
	int max_spec = *max_element(spec_companions.begin(), spec_companions.end());
	for (int i=0;i<normal_count_vertices;i++){
		ans+=(max_spec+i);
	}
	cout<<ans-m<<endl;
}
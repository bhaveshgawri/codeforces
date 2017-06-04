#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > C(54);
vector<int> used(54, 0);
vector<pair<int, int> >react_no;
long long int ans=1;

void bfs(int chemical){
	queue<int> test_tube;
	test_tube.push(chemical);
	used[chemical]=1;
	//cout<<chemical<<endl;
	while(!test_tube.empty()){
		int chem = test_tube.front();
		test_tube.pop();
		vector<pair<int, int> >react_size;
		for (int i: C[chem]){
			react_size.push_back({C[i].size(), i});
		}
		sort(react_size.rbegin(), react_size.rend());
		for (auto it = react_size.begin();it!=react_size.end();++it){
			if (!used[(*it).second]){
				//cout<<(*it).first<<" "<< (*it).second<<endl;
				used[(*it).second]=1;
				test_tube.push((*it).second);
				for (int i: C[(*it).second]){
					//cout<<i<<endl;
					if (used[i]==1){
						//cout<<i<<" ";
						ans*=2;
						break;
					}
				}
			}
		}
	}
}

int main(){
	int n, m, p, q;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>p>>q;
		C[p].push_back(q);
		C[q].push_back(p);
	}
	for (int i=1;i<=n;i++){
		react_no.push_back({C[i].size(), i});
	}
	sort(react_no.rbegin(), react_no.rend());
	for (auto it=react_no.begin();it!=react_no.end();++it){
		if (!used[(*it).second]){
			bfs((*it).second);
		}
	}
	cout<<ans<<endl;
}
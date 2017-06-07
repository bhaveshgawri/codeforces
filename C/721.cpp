#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define f first
#define s second

using namespace std;

vector<vector<pair<int, int> > >B(5004);
vector<vector<int> >time_(5004, vector<int>(5004, INT_MAX/2));
vector<vector<int> >path(5004, vector<int>((5004), 0));
vector<int> visited(5004);

int dfs(int node, int n){
	if (!visited[node]){
		visited[node]=1;
		for (auto i: B[node]){
			if (!visited[i.f])
				dfs(i.f, n);
			for (int j=2;j<=n;j++){
				int temp = time_[i.f][j-1]+i.s;
				if (temp<time_[node][j]){
					time_[node][j]=temp;
					path[node][j]=i.f;
				}
			}
		}
	}
}

int main(){
	int n, m, T, p, q, t;
	cin>>n>>m>>T;
	for(int i=0;i<m;i++){
		cin>>p>>q>>t;
		B[p].pb({q, t});
		//B[q].pb({p, t});
	}
	time_[n][1]=0;
	dfs(1, n);
	/*for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cout<<time_[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int j;
	for (j=n;p>0;j--){
		if (time_[1][j]<=T)
			break;
	}
	cout<<j<<endl;
	for (int node=1;node!=n;node=path[node][j], j--){
		cout<<node<<" ";
	}
	cout<<n<<endl;
}
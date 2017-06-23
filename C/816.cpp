#include <bits/stdc++.h>

#define ll      long long int

#define nl         "\n"
#define pb         push_back
#define ppb        pop_back
#define pf         push_front
#define ppf        pop_front
#define sz(x)      x.size()
#define all(x)     x.begin(), x.end()
#define Sort(x)    sort(all(x))
#define init(x, k) fill(all(x), k)
#define dot(x)     fixed<<setprecision(x) 
#define nfs        ios_base::sync_with_stdio(false);cin.tie(NULL)

#define Max(a, b, c)   max(a, max(b, c))
#define Min(a, b, c)   min(a, min(b, c))
#define mxe(a)        *max_element(all(a))
#define mne(a)        *min_element(all(a))

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
#define ub(x, k)   upper_bound(all(x), k)-x.begin()

#define inf      INT_MAX
#define INF      LLONG_MAX

#define ff    first
#define ss    second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

int main(){
	nfs;
	int n, m;
	cin>>n>>m;
	vector<string> ans;
	vvi g(n, vi(m));
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	if (n<m){
		for (int i=0;i<n;i++){
			int mini = mne(g[i]);
			if (mini>0){
				for (int j=0;j<mini;j++){
					//flag=1;
					ans.pb("row "+to_string(i+1));
					//cout<<"row "+i+1<<nl;
				}
				for (int j=0;j<m;j++){
					g[i][j]-=mini;
				}
			}
		}
		for (int i=0;i<m;i++){
			int mini=inf;
			for (int j=0;j<n;j++){
				if (g[j][i]<mini){
					mini=g[j][i];
				}
			}
			if (mini>0){
				for (int j=0;j<mini;j++){
					//flag=1;
					ans.pb("col "+to_string(i+1));
					//cout<<"col "<<i+1<<nl;
				}
				for (int j=0;j<n;j++){
					g[j][i]-=mini;
				}
			}
		}
	}
	else{
		for (int i=0;i<m;i++){
			int mini=inf;
			for (int j=0;j<n;j++){
				if (g[j][i]<mini){
					mini=g[j][i];
				}
			}
			if (mini>0){
				for (int j=0;j<mini;j++){
					//flag=1;
					ans.pb("col "+to_string(i+1));
					//cout<<"col "<<i+1<<nl;
				}
				for (int j=0;j<n;j++){
					g[j][i]-=mini;
				}
			}
		}	
		for (int i=0;i<n;i++){
			int mini = mne(g[i]);
			if (mini>0){
				for (int j=0;j<mini;j++){
					//flag=1;
					ans.pb("row "+to_string(i+1));
					//cout<<"row "+i+1<<nl;
				}
				for (int j=0;j<m;j++){
					g[i][j]-=mini;
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (g[i][j]!=0){
				cout<<-1<<nl;
				return 0;
			}
		}
	}
	cout<<ans.size()<<nl;
	for (int i=0;i<ans.size();i++){
		cout<<ans[i]<<nl;
	}

}
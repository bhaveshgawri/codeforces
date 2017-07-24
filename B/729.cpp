#include <bits/stdc++.h>

#define ll      long long int

#define nl         "\n"
#define pb         push_back
#define ppb        pop_back
#define pf         push_front
#define ppf        pop_front
#define sz(x)      x.size()
#define all(x)     x.begin(), x.end()
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
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

int main(){
	nfs;
	int n, m;
	cin>>n>>m;
	int p[n][m];
	vii ones;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>p[i][j];
			if (p[i][j]==1)
				ones.pb({i, j});
		}
	}
	int x, y, count=0;
	for (auto one: ones){
		x = one.ff, y = one.ss;
		x--;
		while(x>=0){
			if (p[x][y]==0)count++;
			if (p[x][y]==1)break;
			x--;
		}
		x=one.ff, y--;
		while(y>=0){
			if (p[x][y]==0)count++;
			if (p[x][y]==1)break;
			y--;
		}
		x++, y = one.ss;
		while(x<n){
			if (p[x][y]==0)count++;
			if (p[x][y]==1)break;
			x++;
		}
		x = one.ff, y++;
		while(y<m){
			if (p[x][y]==0)count++;
			if (p[x][y]==1)break;
			y++;
		}
	}
	cout<<count<<nl;

}
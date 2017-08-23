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
#define nfs        ios_base::sync_with_stdio(false)
#define no_step    cin.tie(NULL)

#define Max(a, b, c)   max(a, max(b, c))
#define Min(a, b, c)   min(a, min(b, c))
#define mxe(a)        *max_element(all(a))
#define mne(a)        *min_element(all(a))

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k

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

int n, m, counter=0;
char L[1004][1004];
vvii prop(1004, vii(1004));
vii dots;
vii to_assign;
int visited[1004][1004];

bool isFine(int x, int y){
	if (x>=1 && x<=n && y>=1 && y<=m && L[x][y]=='.' && visited[x][y]==0) return true;
	else return false;
}

bool inLimits(int x, int y){
	if (x>=1 && x<=n && y>=1 && y<=m && L[x][y]=='.') return true;
	else return false;
}

void dfs(ii pt){
	int x = pt.ff, y = pt.ss;
	if (isFine(x, y)){
		visited[x][y] = 1;
		counter++;
		to_assign.pb(pt);
	}
	if (isFine(x+1, y)){
		dfs({x+1, y});
	}
	if (isFine(x-1, y)){
		dfs({x-1, y});
	}
	if (isFine(x, y+1)){
		dfs({x, y+1});
	}
	if (isFine(x, y-1)){
		dfs({x, y-1});
	}
}

void assign(int index, int counter){
	for (ii dot: to_assign)
		prop[dot.ff][dot.ss] = {index, counter};
}

void calc(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (L[i][j]=='*'){
				int ans = 1;
				vi idx;
				if (inLimits(i-1, j)){
					ans+=prop[i-1][j].ss;
					idx.pb(prop[i-1][j].ff);
				}
				if (inLimits(i+1, j)){
					int index = prop[i+1][j].ff;
					if (find(all(idx), index)==idx.end()){
						idx.pb(index);
						ans+=prop[i+1][j].ss;
					}
				}
				if (inLimits(i, j-1)){
					int index = prop[i][j-1].ff;
					if (find(all(idx), index)==idx.end()){
						idx.pb(index);
						ans+=prop[i][j-1].ss;
					}
				}
				if (inLimits(i, j+1)){
					int index = prop[i][j+1].ff;
					if (find(all(idx), index)==idx.end()){
						idx.pb(index);
						ans+=prop[i][j+1].ss;
					}
				}
				cout<<ans%10;
			}
			else
				cout<<'.';
		}
		cout<<nl;
	}
}

void solve(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>L[i][j];
			if (L[i][j]=='.')
				dots.pb({i, j});
		}
	}
	int index = 0;
	for (ii dot: dots){
		if (visited[dot.ff][dot.ss]==0){
			index++;
			counter = 0;
			to_assign.clear();
			dfs(dot);
			assign(index, counter);
		}
	}
	calc();
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
}
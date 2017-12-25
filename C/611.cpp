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

char D[504][504] = {0};
int ans2D[504][504] = {0};
int rans1D[504][504] = {0};
int cans1D[504][504] = {0};

void process(int h, int w){
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){			
			ans2D[i][j] = ans2D[i][j-1] + ans2D[i-1][j]-ans2D[i-1][j-1];
			rans1D[i][j] = rans1D[i][j-1];
			cans1D[i][j] = cans1D[i-1][j];
			if (D[i][j]=='.' && D[i-1][j]=='.') ans2D[i][j]++, cans1D[i][j]++;
			if (D[i][j]=='.' && D[i][j-1]=='.') ans2D[i][j]++, rans1D[i][j]++;
		}
	}	
}

void query(int q){
	int r1, c1, r2, c2;
	while(q--){
		cin>>r1>>c1>>r2>>c2;
		int ans = ans2D[r2][c2]-ans2D[r2][c1]-ans2D[r1][c2]+ans2D[r1][c1]
			  +cans1D[r2][c1]-cans1D[r1][c1]+rans1D[r1][c2]-rans1D[r1][c1];
		cout<<ans<<nl;
	}
}

int main(){
	nfs;
	int h, w;
	cin>>h>>w;
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			cin>>D[i][j];
		}
	}
	process(h, w);
	int q;
	cin>>q;
	query(q);
}
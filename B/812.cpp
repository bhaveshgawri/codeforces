#include <bits/stdc++.h>

#define ll         long long
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
//first element greater or equal to k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k

#define inf      INT_MAX
#define INF      LLONG_MAX

#define ff       first
#define ss       second

using namespace  std;

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 4;

int n, m;
vector<string> v(20);
int floor_sum[20];
vvi cache(20, vi(2, -1));


int calculate(int floor_, int side){
	if (floor_==n+1) return 0;

	if (cache[floor_][side]!=-1)
		return cache[floor_][side];

	if (floor_sum[floor_]==0 && floor_ < n)
		return cache[floor_][side] = 
					1 + calculate(1+floor_, side);
	
	int llast = 0, rlast = m+1;
	for (int i=1;i<=m;i++)
		if (v[floor_][i]=='1')llast = i;
	for (int i=m;i>=0;i--)
		if (v[floor_][i]=='1')rlast = i;
	
	if (floor_==n) return cache[floor_][side] = 
				    side ? m+1-rlast : llast;
	else if (floor_==0) 
		 return cache[floor_][side] = 
						   min(2*llast+1+calculate(floor_+1, 0),
						   m+2+calculate(floor_+1, 1));
	else return cache[floor_][side] = 
					side ? min(2*(m+1-rlast)+1+calculate(floor_+1, 1),
						   m+2+calculate(floor_+1, 0))
						 : min(2*llast+1+calculate(floor_+1, 0),
						   m+2+calculate(floor_+1, 1));
}

void solve(){
	cin>>n>>m;
	for (int i=n-1; i>=0 ;i--){
		cin>>v[i];
		for (char c: v[i])floor_sum[i] += c=='1';
	}
	int d = n;
	n=0;
	for (int i=0;i<d;i++){
		if (floor_sum[i])n=i;
	}
	// cout<<n<<nl;;
	cout<<calculate(0, 0)<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
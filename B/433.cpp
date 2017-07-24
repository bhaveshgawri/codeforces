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
	int n;
	cin>>n;
	vl u(n+1), v(n+1);
	for (int i=1;i<=n;i++){
		cin>>v[i];
		u[i]=v[i];
	}
	u[0]=v[0]=0;
	Sort(u);
	for (int i=1;i<=n;i++){
		v[i]+=v[i-1];
		u[i]+=u[i-1];
	}
	int m, t, l, r;
	cin>>m;
	while(m--){
		cin>>t>>l>>r;
		if (t==1)
			cout<<v[r]-v[l-1]<<nl;
		else
			cout<<u[r]-u[l-1]<<nl;
	}
}
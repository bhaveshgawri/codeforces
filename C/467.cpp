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
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

vl v(5004);
vl sum(5004);
vvl cache(5005, vl(5004, -1));

ll select(int start, int n, int m, int k){
	if (k==0 || start>n){
		return 0;
	}
	if (cache[start][k]!=-1){
		return cache[start][k];
	}
	int l=start, r=start+m-1;
	if (r<=n)
		cache[start][k] = max(cache[start][k], sum[r]-sum[l-1]+select(start+m, n, m, k-1));
	return cache[start][k] = max(cache[start][k], select(start+1, n, m, k));
}

int main(){
	nfs;
	int n, m, k;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		cin>>v[i];
		sum[i]=v[i];
	}
	sum[0]=0ll;
	for (int i=2;i<=n;i++){
		sum[i]+=sum[i-1];
	}
	cout<<select(1ll, n, m, k)<<nl;
}
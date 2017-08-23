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
const int hi = 1e7+4;

vi lp(hi);
vi prime;
vi ans(hi, 0);
vi visited(hi, 0);

void primes(){
	for (int i=2;i<=hi;i++){
		if (lp[i]==0){
			lp[i] = i;
			prime.pb(i);
		}
		for (int j=0;j<(int)prime.size() && prime[j]<=lp[i] && i*prime[j]<=hi;j++){
			lp[i*prime[j]] = prime[j];
		}
	}
}

void factorize(int n){
	vi pr_fac;
	while(n!=1){
		if (visited[lp[n]]==0){
			ans[lp[n]]++;
			visited[lp[n]]=1;
			pr_fac.pb(lp[n]);
		}
		n/=lp[n];
	}
	for (int i: pr_fac){
		visited[i] = 0;
	}
}

void solve(){
	primes();
	int n, p;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>p;
		factorize(p);
	}
	for (int i=1;i<hi;i++){
		ans[i]+=ans[i-1];
	}
	int m, l, r;
	cin>>m;
	while(m--){
		cin>>l>>r;
		if (r>hi)r=hi-1;
		if (l>hi)l=hi-1;
		cout<<ans[r]-ans[l-1]<<nl;
	}
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
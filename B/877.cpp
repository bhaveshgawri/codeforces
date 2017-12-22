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

vector<pair<int, int>>v;
vi a(2004), b(2004);

void solve(){
	string s;
	cin>>s;
	s="z"+s;
	int l = s.length();
	for (int i=0;i<l;i++){
		if (s[i]=='a'){
			if (i>=1) a[i]=1+a[i-1], b[i]=b[i-1];
			else a[i]=1, b[i]=0;		
		}
		else{
			if (i>=1) a[i]=a[i-1], b[i]=1+b[i-1];
			else a[i]=0, b[i]=1;
		}
	}
	int ans=-inf;
	for (int i=1;i<l;i++){
		for (int j=i;j<l;j++){
			ans = max(ans, a[i]+a[l-1]-a[j]+b[j]-b[i]);
			cout<<i<<" "<<j<<" "<<a[i]+a[l-1]-a[j]+b[j]-b[i]<<nl;
		}
	}
	cout<<ans<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
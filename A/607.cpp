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
	no_step;
	int n;
	cin>>n;
	int hi=-1, p, q;
	vii a(1000004, {0,0}); 
	vi ans(1000004, 0);
	for (int i=1;i<=n;i++){
		cin>>p>>q;
		a[p].ff=1;
		a[p].ss=q;
		hi=max(p, hi);
	}
	for (int i=0;i<=hi;i++){
		if (!a[i].ff && i!=0){
			ans[i]=ans[i-1];
		}
		else if (!a[i].ff && i==0){
		    ans[i]=0;
		}
		else{
			int x = i-a[i].ss-1>=0?i-a[i].ss-1:1000003;
			//1000003: just wanted to select a pos where ans[pos]=0	
			ans[i]=1+ans[x];
		}
	}
	cout<<n-mxe(ans)<<nl;
}
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
	vi a(n), count(10*Max1, 0);
	int _max=-inf;
	for (int i=0;i<n;i++){
		cin>>a[i];
		count[a[i]]++;
		if (count[a[i]]>_max)
			_max=count[a[i]];
	}
	vii v;
	for (int i=0;i<n;i++){
		if (count[a[i]]==_max){
			v.pb({a[i], i});
		}
	}
	sort(all(v));
	int ans = inf;
	int ansi, ansj;
	for (int i=0;i<v.size();i++){
		int mx=-inf;
		int mn=inf;
		int j=i;
		while(v[i].ff==v[i+1].ff){
			i++;
		}
		for (int k=j;k<=i;k++){
			if (mx<=v[k].ss){
				mx=v[k].ss;
			}
			if (mn>=v[k].ss){
				mn=v[k].ss;
			}
		}
		if (mx-mn<ans){
			ansj=mx;
			ansi=mn;
			ans=mx-mn;
		}
	}
	cout<<++ansi<<" "<<++ansj<<nl;
}
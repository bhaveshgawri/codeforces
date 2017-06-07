#include <bits/stdc++.h>

#define ll      long long int
#define u64     unsigned long long int

#define nl      "\n"
#define pb      push_back
#define ppb     pop_back
#define pf      push_front
#define ppf     pop_front
#define sz(x)   x.size()
#define all(x)  x.begin(), x.end()
#define nfs     ios_base::sync_with_stdio(false);cin.tie(NULL)

#define _max(a, b, c)   max(a, max(b, c))
#define _min(a, b, c)   min(a, min(b, c))
#define mxe(a)          *max_element(all(a))
#define mne(a)          *min_element(all(a))

#define lb(x, k) lower_bound(all(x), k)-x.begin()
#define ub(x, k) upper_bound(all(x), k)-x.begin()

#define inf      INT_MAX
#define minf     INT_MIN
#define INF      LLONG_MAX
#define MINF     LLONG_MIN

#define f   first
#define s 	second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MAX = 1e5 + 4;
const int MOD = 1e9 + 7;

int main(){
	nfs;
	string s;
	cin>>s;
	vi ans(sz(s), 0);
	for (int i=1;i<sz(s);i++){
		if (s[i-1]==s[i])
			ans[i]=ans[i-1]+1;
		else
			ans[i]=ans[i-1];
	}
	int q, l, r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<ans[r-1]-ans[l-1]<<nl;
	}
}
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

int main(){
	nfs;
	int sl, tl;
	cin>>sl>>tl;
	string s, t;
	cin>>s>>t;
	vector<string> v;
	vvi freq(1004);
	for(int i=0;i<tl-sl+1;i++){
		string m="";
		for (int j=0;j<sl;j++){
			m+=t[i+j];
		}
		v.pb(m);
	}
	for (int i=0;i<v.size();i++){
		for (int j=0;j<sl;j++){
			if (s[j]!=v[i][j]){
				freq[i].pb(j+1);
			}
		}
	}
	int min_sz=inf;
	int idx;
	for (int i=0;i<v.size();i++){
		if (freq[i].size()<min_sz){
			min_sz=freq[i].size();
			idx=i;
		}
	}
	vi ans=freq[idx];
	cout<<ans.size()<<nl;
	for (int i: ans)cout<<i<<" ";
	cout<<nl;
}
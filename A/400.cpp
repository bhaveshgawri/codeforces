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
	int t;
	cin>>t;
	while(t--){
		vector<string> ans;
		int count=0;
		string s;
		cin>>s;
		for (int i=1;i<=12;i++){
			if (i==1||i==2||i==3||i==4||i==6||i==12){
				map<int, int> mp;
				int cols=12/i;
				int rows=i;
				for (int j=0;j<12;j++){
					s[j]=='X'?mp[j%cols]++:mp[j%cols]=0;
				}
				for (auto i: mp)
					if (i.ss==rows){
						ans.pb(to_string(rows)+"x"+to_string(cols));
						break;
					}
			}
		}
		cout<<ans.size()<<" ";
		for (string answer: ans) cout<<answer<<" ";
		cout<<nl;
	}
}
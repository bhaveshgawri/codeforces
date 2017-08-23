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

bool comp(const pair<ii, int> &a,const pair<ii, int> &b){
	//desc
	if (a.ff.ss!=b.ff.ss)
		return a.ff.ss>b.ff.ss;
	else return a.ff.ff<b.ff.ff;
}

void solve(){
	int n;
	cin>>n;
	vector<pair<ii, int>> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i].ff.ff>>v[i].ff.ss;
		v[i].ss = i+1;
	}
	int r, p;
	cin>>r;
	vector<set<int>> vs(1004);
	multiset<int> ms;
	for (int i=0;i<r;i++){
		cin>>p;
		vs[p].insert(i+1);
		ms.insert(p);
	}
	sort(all(v), comp);
	vii ans;
	int sum = 0, counter = 0;
	for (auto i: v){
		auto it = ms.lower_bound(i.ff.ff);
		if (it!=ms.end()){
			counter++;
			sum+=i.ff.ss;
			ans.pb({i.ss, *vs[*it].begin()});
			vs[*it].erase(vs[*it].begin());
			ms.erase(it);
		}
	}
	cout<<counter<<" "<<sum<<nl;
	for (ii i: ans)cout<<i.ff<<" "<<i.ss<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
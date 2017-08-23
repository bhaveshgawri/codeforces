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

ll level(ll n){
	ll level = 0;
	if (n && !(n&(n-1))){
		ll pp = n;
		while(pp){
			pp/=2;
			level++;
		}
		return level;
	}
	else{
		n--;
		n|=n>>1;
		n|=n>>2;
		n|=n>>4;
		n|=n>>8;
		n|=n>>16;
		n|=n>>32;
		ll pp = ++n;
		while(pp){
			pp/=2;
			level++;
		}
		return --level;
	}
}

set<II> edge_list(ll u, ll v){
	set<II> edges;
	ll levelu = level(u);
	ll levelv = level(v);
	ll temp, other;
	if (levelu > levelv){
		temp = u;
		other = v;
	}
	else{
		temp = v;
		other = u;
	}
	while(temp>1){
		edges.insert({temp/2, temp});
		temp/=2;
	}
	while(other>1){
		II edge = {other/2, other};
		if (!(edges.find(edge)!=edges.end())){
			edges.insert(edge);
		}
		else{
			edges.erase(edge);
		}
		other/=2;
	}
	return edges;
}

void solve(){
	ll q;
	cin>>q;
	map<II, ll> cost;
	while(q--){
		ll p, u, v;
		cin>>p;
		if (p==1){
			ll w;
			cin>>u>>v>>w;
			set<II> edges = edge_list(u, v);
			for (II edge: edges)
				cost[edge]+=w;
		}
		else if (p==2){
			cin>>u>>v;
			ll ans = 0;
			set<II> edges = edge_list(u, v);
			for (II edge: edges)
				ans+=cost[edge];
			cout<<ans<<nl;
		}
	}
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
}
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

vi v1, v2;

bool equ(vi& va, vi& vb){
	for (int i=0;i<va.size();i++){
		if (va[i]!=vb[i])return false;
	}
	return true;
}

vi cmp(){
	int l1 = v1.size();
	int l2 = v2.size();
	if (l1>l2 && equ(v1, v2)){
		return v1;
	}
	else if (l2>l1 && equ(v2, v1)){
		return v2;
	}
	else{
		int i=0;
		int l = min(l1, l2);
		while(i<l && v1[i]==v2[i]){
			i++;
		}
		if (i!=l){
			if (v1[i]>v2[i])return v1;
			else if (v2[i]>v1[i])return v2;
		}
		else{
			vi v;
			v.pb(-1);
			return v;
		}
	}
}

void solve(){
	ll n, p, sc1=0, sc2=0, end=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p;
		if (p>0){
			sc1+=p;
			end=1;
			v1.pb(p);
		}
		else{
			p=-p;
			sc2+=p;
			end=2;
			v2.pb(p);
		}
	}
	string first = "first";
	string second = "second";
	if (sc1>sc2)cout<<first<<nl;
	else if (sc2>sc1)cout<<second<<nl;
	else{
		if (cmp()==v1)cout<<first<<nl;
		else if (cmp()==v2)cout<<second<<nl;
		else{
			if (end==1)cout<<first<<nl;
			else cout<<second<<nl;
		}
	}
}

int main(){
	nfs;
	// no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
}
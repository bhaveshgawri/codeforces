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

vl parent(Max1);
map<ll, ll> sum;
vl recons(Max1, -1);
vl a(Max1);
vl index_(Max1);
vl ans;

ll root(ll i){
	while(parent[i]!=i){
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}

void union_(ll x, ll y){
	ll rootx = root(x);
	ll rooty = root(y);
	parent[rootx] = rooty;
}

void calculate_ans(ll n){
	ans.pb(0);
	for (ll i=n-1;i>0;i--){
		recons[index_[i]-1] = a[index_[i]-1];
		ll ele;
		if (index_[i]-1>0 && index_[i]-1<n-1){
			if (recons[index_[i]-2]!=-1 && recons[index_[i]]!=-1){
				ll s1=recons[index_[i]-1];
				ll s2=sum[parent[root(index_[i]-2)]];
				ll s3=sum[parent[root(index_[i])]];
				union_(index_[i]-1, index_[i]-2);
				union_(index_[i]-1, index_[i]);
				ele = parent[root(index_[i]-1)];
				sum[ele] = s1+s2+s3;
			}
			else if (recons[index_[i]-2]!=-1 && recons[index_[i]]==-1){
				ll s1=recons[index_[i]-1];
				ll s2=sum[parent[root(index_[i]-2)]];
				union_(index_[i]-1, index_[i]-2);
				ele = parent[root(index_[i]-1)];
				sum[ele] = s1+s2;
			}
			else if (recons[index_[i]-2]==-1 && recons[index_[i]]!=-1){
				ll s1=recons[index_[i]-1];
				ll s3=sum[parent[root(index_[i])]];
				union_(index_[i]-1, index_[i]);
				ele = parent[root(index_[i]-1)];
				sum[ele] = s1+s3;
			}
			else{
				ele = index_[i]-1;
				sum[ele] = recons[index_[i]-1];
			}
		}
		else if (index_[i]-1==0){
			if (recons[index_[i]]==-1){
				ele = index_[i]-1;
				sum[ele] = recons[index_[i]-1];
			}
			else if (recons[index_[i]]!=-1){
				ll s1=recons[index_[i]-1];
				ll s3=sum[parent[root(index_[i])]];
				union_(index_[i]-1, index_[i]);
				ele = parent[root(index_[i]-1)];
				sum[ele] = s1+s3;
			}
		}
		else if (index_[i]-1==n-1){
			if (recons[index_[i]-2]==-1){
				ele = index_[i]-1;
				sum[ele] = recons[index_[i]-1];
			}
			else if (recons[index_[i]-2]!=-1){
				ll s1=recons[index_[i]-1];
				ll s2=sum[parent[root(index_[i]-2)]];
				union_(index_[i]-1, index_[i]-2);
				ele = parent[root(index_[i]-1)];
				sum[ele] = s1+s2;
			}
		}
		ans.pb(max(ans[ans.size()-1], sum[ele]));
	}
	reverse(all(ans));
}

void solve(){
	ll n;
	cin>>n;
	for (ll i=0;i<n;i++){
		parent[i]=i;
		sum[i]=i+1;
	}
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}
	for (ll i=0;i<n;i++){
		cin>>index_[i];
	}
	calculate_ans(n);
	for (ll i: ans)cout<<i<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
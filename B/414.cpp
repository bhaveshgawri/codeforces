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

vvi factors(2004);
ll ans=0;
int cache[2004][2004];

void factorize_upto(int n){
	for (int i=1;i<=n;i++){
		for (int j=1;j*j<=i;j++){
			if (i%j==0 && j*j!=i)
				factors[i].pb(j), factors[i].pb(i/j);
			else if (i%j==0 && j*j==i)
				factors[i].pb(j);
		}
	}
}

int find(int num, int pos){
	if (pos==1){
		return 1;
	}
	if (cache[num][pos]!=-1)
		return cache[num][pos];
	int temp_ans=0;
	for (int i: factors[num]){
		//temp_ans+=find(i, pos-1);
		temp_ans = (temp_ans%Mod + find(i, pos-1)%Mod)%Mod;
	}
	return cache[num][pos] = temp_ans;
}

void calculate(int n, int k){
	for (int i=1;i<=n;i++){
		ans += find(i, k);
		if (ans>Mod)
			ans%=Mod;
	}
	cout<<ans<<nl;
}

int main(){
	nfs;
	int n, k;
	int ans[n+1][k+1];
	for (int i=0;i<2004;i++){
		for(int j=0;j<2004;j++){
			cache[i][j]=-1;
		}
	}
	cin>>n>>k;
	factorize_upto(n);
	calculate(n, k);
}
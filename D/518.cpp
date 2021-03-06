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



// sol 1

long double r[2004];

void nCr(int t){
	r[0] = 1;
	for (int i=0;i<=t;i++){
		for (int j=i;j>0;j--){
			r[j] += r[j-1];
		}
	}
}

void solve(){
	int n, t;
	long double p;
	cin>>n>>p>>t;
	nCr(t);
	long double ans = 0;
	if (n>=t){
		for (int i=1;i<=t;i++){
			ans += i*r[i]*pow(p, i)*pow(1-p, t-i);
		}
	}
	else{
		for (int i=1;i<n;i++){
			ans += i*r[i]*pow(p, i)*pow(1-p, t-i);
		}
		long double combination = r[n];
		int nr = n, dr = t;
		combination = ((long double)nr/dr)*combination;
		nr = t-n, dr = t-1;
		for (int i=t;i>=n;i--){
			ans += n*combination*pow(p, n-1)*pow(1-p, i-n)*p;
			combination *= (((long double)nr)/dr);
			nr--, dr--;
		}
	}
	cout<<dot(6)<<ans<<nl;
}


int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
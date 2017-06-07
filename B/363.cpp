#include <bits/stdc++.h>

#define ll      long long int
#define u64     unsigned long long int

#define nl       "\n"
#define pb       push_back
#define ppb      pop_back
#define pf       push_front
#define ppf      pop_front
#define sz(x)    x.size()
#define all(x)   x.begin(), x.end()
#define nfs      ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dot(x)   fixed<<setprecision(x) 

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

#define f    first
#define s    second

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

double min_d(double a, double b){
	return a>b?b:a;
}

int main(){
	nfs;
	int n, k;
	cin>>n>>k;
	vi v(n+1);
	for (int i=1;i<=n;i++){
		cin>>v[i];
	}
	v[0]=0;
	for (int i=2;i<=n;i++){
		v[i]=v[i]+v[i-1];
	}
	double temp=0.0;
	double mini=inf;
	for (int i=k;i<=n;i++){
		temp = (double(v[i]-v[i-k]))/k;
		mini = min_d(temp, mini);
	}
	int ans=0;
	for (int i=k;i<=n;i++){
		if ((double(v[i]-v[i-k]))/k==mini){
			ans=i-k+1;
			break;
		}
	}
	cout<<ans<<nl;
}
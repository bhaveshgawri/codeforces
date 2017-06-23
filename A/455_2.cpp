#include <bits/stdc++.h>

#define ll      long long int
#define u64     unsigned long long int

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

vl a(MAX, 0), count_(MAX, 0), cache(MAX, INF);

ll calc(int n, int p){
	if (cache[p]!=INF){
		return cache[p];
	}
	if (p==0){
		return 0;
	}
	else if (n==1){
		return a[1];
	}
	else if (p==1 && n!=1){
		return count_[1];
	}
	else{
		for (int i=2;i<MAX;i++){
			cache[i] = max(calc(n, i-1), calc(n, i-2)+i*count_[i]);
		}
		//cache[n] = calc(n);
	}
	return cache[MAX-1];
}

int main(){
	nfs;
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		count_[a[i]]++;
	}
	cout<<calc(n, nl)<<nl;
}
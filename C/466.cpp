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

int main(){
	nfs;
	int n;
	ll sum=0;
	cin>>n;
	vl v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	//for (int i=1;i<n;i++){
	//	v[i]=v[i]+v[i-1];
	//}
	if (sum%3!=0 || n<3){
		cout<<0<<nl;
		return 0;
	}
	int s=0, e=n-1, suml=v[s], sumr=v[e];
	while(1){
		if (sumr==sumr==sum/3){
			count++;
		}
		else if (sumr>suml || sumr==sum/3){
			s++;
			suml+=v[s];
		}
		else if (sumr>suml || suml==sum/3){
			e--;
			sumr+=v[e];
		}
	}
}
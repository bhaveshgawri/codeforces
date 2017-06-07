#include <bits/stdc++.h>

#define ll 		long long int
#define u64 	unsigned long long int

#define nl 		"\n"
#define pb 		push_back
#define ppb 	pop_back
#define pf 		push_front
#define ppf 	pop_front
#define sz(x) 	x.size()
#define all(x) 	x.begin(), x.end()
#define nfs 	ios_base::sync_with_stdio(false);cin.tie(NULL)

#define _max(a, b, c)	max(a, max(b, c))
#define _min(a, b, c)	min(a, min(b, c))
#define mxe(a)			*max_element(all(a))
#define mne(a)			*min_element(all(a))

#define lb(x, k) lower_bound(all(x), k)-x.begin()
#define ub(x, k) upper_bound(all(x), k)-x.begin()

#define inf INT_MAX
#define minf INT_MIN
#define INF LLONG_MAX
#define MINF LLONG_MIN

#define f 	first
#define s 	second

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
	int n, d, h;
	cin>>n>>d>>h;
	if (n<d || 2*h<d || n<h || n<d || (d==1&&n!=2)){
		cout<<-1<<nl;
	}
	else{
		int last;
		for (int i=1;i<=h;i++){
			cout<<i<<" "<<i+1<<nl;
			last=i+1;
		}
		int other_height=d-h;
		n-=h;
		if (other_height>0)
			cout<<1<<" "<<1+last<<nl;
		for (int i=1;i<other_height;i++){
			cout<<i+last<<" "<<i+1+last<<nl;
		}
		last+=other_height;
		n-=other_height;
		for (int i=1;i<n;i++){
			if (other_height==0)
				cout<<2	<<" "<<i+last<<nl;
			else
				cout<<1<<" "<<i+last<<nl;
		}
	}
}
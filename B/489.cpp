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

#define inf  INT_MAX
#define minf INT_MIN
#define INF  LLONG_MAX
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
	int b;
	cin>>b;
	vi boys(b);
	for (int i=0;i<b;i++){
		cin>>boys[i];
	}
	sort(all(boys));
	int g;
	cin>>g;
	vi girl(g);
	for (int i=0;i<g;i++){
		cin>>girl[i];
	}
	sort(all(girl));
	int bptr=0;
	int gptr=0;
	int count=0;
	while(1){
		if (bptr==b || gptr==g)
			break;
		if (abs(boys[bptr]-girl[gptr])<=1){
			count++;
			bptr++;gptr++;
		}
		else if (boys[bptr]-girl[gptr] > 1){
			gptr++;
		}
		else if (girl[gptr] - boys[bptr] > 1){
			bptr++;
		}
	}
	cout<<count<<nl;
}
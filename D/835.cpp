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

int ans[5004];
vvi cache(5004, vi(5004, 0));
string s;

int calc(int start, int end){
	if (start==end){
		return cache[start][start] = 1;
	}
	if (start==end-1){
		if (s[start]==s[end])
			return cache[start][end] = 2;
		else
			return cache[start][end] = 0;
	}
	if (start>end){
		return 0;
	}
	int len = end-start+1, mid;
	if (len%2==0)
		mid = (start+end)/2;
	else
		mid = (start+end)/2-1;
	if (s[start]==s[end] && cache[start+1][end-1]){
		cache[start][end] = 1 + cache[start][mid];
	}
	return cache[start][end];
}

void solve(){
	cin>>s;
	int l = s.length();

	for (int i=1;i<=l;i++)
		for (int j=0;i+j-1<l;j++)
			calc(j, i+j-1);

	for (int i=0;i<l;i++)
		for (int j=0;j<l;j++)
			ans[cache[i][j]]++;
	
	for (int i=l-1;i>0;i--)
		ans[i-1]+=ans[i];

	for (int i=1;i<=l;i++)cout<<ans[i]<<" ";
	cout<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
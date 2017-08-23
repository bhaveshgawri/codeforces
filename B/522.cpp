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

vl mmaxx(4*Max2);
vl ssumm(4*Max2);
vl height(Max2);
vl width(Max2);

void build(int node, int start, int end){
	if (start==end){
		mmaxx[node] = height[start];
		ssumm[node] = width[start];
		return;
	}
	int mid = (start+end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	
	ssumm[node] = ssumm[2*node] + ssumm[2*node+1];
	mmaxx[node] = max(mmaxx[2*node], mmaxx[2*node+1]);
}

ll query(int node, int start, int end ,int l, int r, char t){
	if (l<=start && r>=end){
		return t=='s'?ssumm[node]:mmaxx[node];
	}
	if (start>r || end<l || start>end){
		return t=='s'?0:-inf;
	}
	int mid = (start+end)/2;
	ll q1 = query(2*node, start, mid, l, r, t);
	ll q2 = query(2*node+1, mid+1, end, l, r, t);
	return t=='s'?(ll)(q1+q2):max(q1, q2);
}

void solve(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>width[i]>>height[i];	
	}
	build(1, 0, n-1);
	for (int i=0;i<n;i++){
		ll sq1 = query(1, 0, n-1, 0, i-1, 's');
		ll sq2 = query(1, 0, n-1, i+1, n-1, 's');
		ll sq = sq1+sq2;
		ll mq1 = query(1, 0, n-1, 0, i-1, 'm');
		ll mq2 = query(1, 0, n-1, i+1, n-1, 'm');
		ll mq = max(mq1, mq2);
		cout<<sq*mq<<" ";
	}
	cout<<nl;

}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
}
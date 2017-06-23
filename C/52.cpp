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

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

vi a(Max2), tree(4*Max2), lazy(4*Max2);

void build(int node, int start, int end){
	if (start==end){
		tree[node]=a[start];
	}
	else{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node]=min(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int left, int right, int value){
	if (lazy[node]!=0){
		tree[node]+=lazy[node];
		if (start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if (right<	start || left > end || start > end)
		return;
	if (left<=start && right>=end){
		tree[node]+=value;
		if (start!=end){
			lazy[2*node] += value;
			lazy[2*node+1] += value;
		}
		return;
	}
	int mid = (start+end)/2;
	update(2*node, start, mid, left, right, value);
	update(2*node+1, mid+1, end, left, right, value);
	tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int node, int start, int end, int left, int right){
	if (right<start || left>end || start>end){
		return inf;
	}
	if (lazy[node]!=0){
		tree[node]+=lazy[node];
		if (start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if (left<=start && right>=end){
		return tree[node];
	}
	int mid = (start+end)/2;
	int q1 = query(2*node, start, mid, left, right);
	int q2 = query(2*node+1, mid+1, end, left, right);
	int ans = min(q1, q2);
	return ans;
}

int main(){
	nfs;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}	
	build(1, 0, n-1);
	int q;
	string s;
	scanf("%d ", &q);
	while(q--){
		getline(cin, s);
		stringstream ss(s);
		int l, r, v=-inf;
		ss>>l>>r;
		if (ss>>v){
			if (r>=l)
				update(1, 0, n-1, l, r, v);
			else
				update(1, 0, n-1, 0, r, v), update(1, 0, n-1, l, n-1, v);
		}
		else{
			if (r>=l)
				cout<<query(1, 0, n-1, l, r)<<nl;
			else
				cout<<min(query(1, 0, n-1, 0, r), query(1, 0, n-1, l, n-1))<<nl;
		}
	}
}
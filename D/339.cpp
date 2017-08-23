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

vi input(10000004);
vi tree(10000004);

int build(int node, int start, int end){
	if (start==end){
		tree[node] = input[start];
		return 1;
	}
	else{
		int mid = (start+end)/2;
		int fir = build(2*node, start, mid);
		int sec = build(2*node+1, mid+1, end);
		int check = fir & sec;
		if (check == 1){
			tree[node] = tree[2*node]|tree[2*node+1];
			return 0;
		}
		else if (check==0){
			tree[node] = tree[2*node]^tree[2*node+1];
			return 1;
		}
	}
}

int update(int node, int start, int end, int index, int value){
	if (start == end){
		tree[node] = value;
		return 1;
	}
	else{
		int mid = (start + end)/2;
		int check;
		if (index >= start && index <= mid){
			check = update(2*node, start, mid, index, value);
		}
		else if (index>mid && index <= end){
			check = update(2*node+1, mid+1, end, index, value);
		}
		if (check == 1){
			tree[node] = tree[2*node]|tree[2*node+1];
			return 0;
		}
		else if (check==0){
			tree[node] = tree[2*node]^tree[2*node+1];
			return 1;
		}
	}
}

void solve(){
	int n, m, p, b;
	cin>>n>>m;
	for (int i=1;i<=(1<<n);i++){
		cin>>input[i];
	}
	build(1, 1, 1<<n);
	while(m--){
		cin>>p>>b;
		update(1, 1, 1<<n, p, b);
		cout<<tree[1]<<nl;
	}
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
}
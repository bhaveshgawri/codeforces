#include <bits/stdc++.h>

#define ll      long long int

#define nl         "\n"
#define pb         push_back
#define ppb        pop_back
#define pf         push_front
#define ppf        pop_front
#define sz(x)      x.size()
#define all(x)     x.begin(), x.end()
#define Sort(x)    sort(all(x))
#define init(x, k) fill(all(x), k)
#define dot(x)     fixed<<setprecision(x) 
#define nfs        ios_base::sync_with_stdio(false);cin.tie(NULL)

#define Max(a, b, c)   max(a, max(b, c))
#define Min(a, b, c)   min(a, min(b, c))
#define mxe(a)        *max_element(all(a))
#define mne(a)        *min_element(all(a))

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
#define ub(x, k)   upper_bound(all(x), k)-x.begin()

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
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

int SF[1004][1004];
vi parent(1004);

void initialize(int n){
	for (int i=1;i<=n;i++){
		parent[i]=i;
	}
}

int root(int i){
	while(i!=parent[i]){
		parent[i] = parent[parent[i]];
		i=parent[i];
	}
	return i;
}

int union_(int x, int y){
	int rootx = root(x);
	int rooty = root(y);
	parent[rootx]=rooty;
}

int main(){
	nfs;
	int n, p, q;
	cin>>n;
	initialize(n);
	for (int i=1;i<=n;i++){
		cin>>p>>q;
		SF[p][q]=i;
		for (int j=1;j<=n;j++)
			if (SF[p][j]!=0)
				cout<<i<<" "<<SF[p][j]<<nl, union_(i, SF[p][j]);
		for (int j=1;j<=n;j++)
			if (SF[j][q]!=0)
				cout<<i<<" "<<SF[j][q]<<nl, union_(i, SF[j][q]);
	}
	int _count=0;
	sort(parent.begin(), parent.begin()+n);
	for (int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<nl;
	for (int i=1;i<=n-1;i++){
		if (parent[i]!=parent[i+1])
			_count++;
	}
	cout<<_count<<nl;
}
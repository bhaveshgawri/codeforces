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

void solve(){
	int n;
	cin>>n;
	vi v(n), c(n);
	vi occured(Max2, 0), last(Max2);
	priority_queue<int, vi, greater<int>>pq;
	set<int> rep;
	for (int i=0;i<n;i++){
		cin>>v[i];
		c[i]=v[i];
	}
	sort(all(c));
	for (int i=0;i<n-1;i++){
		if (c[i]==c[i+1]){
			rep.insert(c[i]);
		}
	}
	for (int i=1;i<=200000;i++){
		if (!binary_search(all(c), i)){
			pq.push(i);
		}
	}
	for (int i=0;i<n;i++){
		last[v[i]]=i;
	}
	int count=0;
	for (int i=0;i<n;i++){
		if (rep.find(v[i])!=rep.end()){
			if (pq.top()<v[i] && last[v[i]]!=i || occured[v[i]]){
				v[i]=pq.top();
				pq.pop();
				count++;
			}
			occured[v[i]]=1;
		}
	}
	cout<<count<<nl;
	for (int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
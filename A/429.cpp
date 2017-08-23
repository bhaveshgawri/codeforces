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
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

vi initial(Max1), final(Max1);
vi ans;
vvi  T(Max1);

void calc(int x){
	queue<pair<ii, int> > q;
	vi visited(Max1, 0);
	visited[x]=1;
	q.push({{x, 0}, 0});
	while(!q.empty()){
		auto top = q.front();
		q.pop();
		int node = top.ff.ff;
		int pflip = top.ff.ss;
		int gflip = top.ss;
		int flip;
		if (gflip == 0){
			if (initial[node]!=final[node]){
				ans.pb(node);
				flip = 1;
			}
			else{
				flip = 0;
			}
		}
		else{
			if (initial[node]!=final[node]){
				flip = 1;
			}
			else{
				flip=0;
				ans.pb(node);
			}	
		}
		for (int i: T[node]){
			if (visited[i]==0){
				q.push({{i, flip}, pflip});
				visited[i]=1;
			}
		}
	}
}

int main(){
	nfs;
	no_step;
	int n, p, q;
	cin>>n;
	for (int i=0;i<n-1;i++){
		cin>>p>>q;
		T[p].pb(q);
		T[q].pb(p);
	}
	for (int i=1;i<=n;i++){
		cin>>initial[i];
	}
	for (int i=1;i<=n;i++){
		cin>>final[i];
	}
	calc(1);
	cout<<ans.size()<<nl;
	for (int i: ans)cout<<i<<nl;
}
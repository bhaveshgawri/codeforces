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

vvi T(Max2);
vi parent(Max2, -1);
vi level(Max2, -1);

void parents_and_level(int x){
	queue<ii> q;
	q.push({x, 0});
	level[x] = 1;
	while(!q.empty()){
		ii top = q.front();
		q.pop();
		parent[top.ff]=top.ss;
		for (int i: T[top.ff]){
			if (i!=top.ss){
				q.push({i, top.ff});
				level[i] = level[top.ff]+1;
			}
		}
	}
}

int height(int x){
	if (T[x].size()==1 && T[x][0]==parent[x])
		return 0;
	int maxx = -1;
	for (int i: T[x]){
		if (i==parent[x])continue;
		maxx = max(maxx, height(i));
	}
	return maxx+1;
}


int main(){
	nfs;
	no_step;
	int n, x, p, q;
	cin>>n>>x;
	for (int i=0;i<n-1;i++){
		cin>>p>>q;
		T[p].pb(q);
		T[q].pb(p);
	}
	parents_and_level(1);
	int a = 1, b = x;
	int lvl_diff = level[b]-level[a];
	int counter=0;
	while(lvl_diff>2){
		b = parent[b];
		lvl_diff-=2;
		counter++;
	}
	int ans =  counter + lvl_diff + height(b);
	cout<<ans+ans<<nl;
}
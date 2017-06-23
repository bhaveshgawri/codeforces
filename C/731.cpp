#include <bits/stdc++.h>

#define ll      long long int
#define u64     unsigned long long int

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

const int MAX = 1e5 + 4;
const int MOD = 1e9 + 7;

vi color(200004, 0);
vi visited(200004, 0);
vvi S(200004);
vvi table(200004);

void dfs(int i, int component){
	if (!visited[i]){
		visited[i]=1;
		table[component].pb(i);
		for (int j: S[i]){
			dfs(j, component);
		}
	}
}

int main(){
	//nfs;
	int n, m, k, l, r;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1;i<=n;i++){
		scanf("%d", &color[i]);
	}
	for (int i=1;i<=m;i++){
		scanf("%d %d", &l, &r);
		S[l].pb(r);
		S[r].pb(l);
	}
	int components=0;
	for (int i=1;i<=n;i++){
		if (!visited[i]){
			++components;
			dfs(i, components);
		}
	}
	int ans=0;
	vi color_count(200004, 0);
	//if ^ was created inside the outer for loop
	//it'd run linear time (200000 operations) for
	//each component => TLE if number(components)=200000 
	for (int i=1;i<=components;i++){
		int max_color=-1;
		for (int j: table[i]){
			color_count[color[j]]++;
			if (color_count[color[j]]>max_color){
				max_color=color_count[color[j]];
			}
		}
		for (int j: table[i]){
			color_count[color[j]]--;
			//instead of clearing whole array in linear time
			//clear only those whose count increased.
		}
		ans+=(sz(table[i])-max_color);
	}
	printf("%d\n",ans);
}
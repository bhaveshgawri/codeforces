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

vvii r(104);
vi source(104, 0), sink(104, 0);
vi visited(104, 0), counta(104, 0), countb(104, 0);
int sum1=0, sum2=0, flag=0;
int start=-1;


void dfs(int node){
	if (visited[node]==0){
		visited[node]=1;
		for (auto i: r[node]){
			if (flag==0 && visited[i.ff]==0)
				sum1+=i.ss;
			else if (flag==1 && visited[i.ff]==0)
				sum2+=i.ss;
			if ((source[i.ff]==1 || sink[i.ff]==1) && visited[i.ff]==0)
				flag=!flag;
			dfs(i.ff);
		}
	}
}

int main(){
	nfs;
	int n, a, b, p, tot_cost=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>b>>p;
		r[a].pb({b, p});
		r[b].pb({a, p});
		countb[b]++;
		counta[a]++;
		if (counta[a]==2)
			source[a]=1;
		if (countb[b]==2)
			sink[b]=1;
	}
	for (int i=1;i<104;i++){
		if (source[i]==1){
			start = i;
			break;
		}
	}
	if (start==-1){
		cout<<0<<nl;
		return 0;
	}
	dfs(start);
	sum2+=r[start][1].ss;
	cout<<min(sum1, sum2)<<nl;
}
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

int main(){
	nfs;
	no_step;
	int n, m;
	char r;
	ii start;
	int flag=0;
	cin>>n>>m>>r;
	vector<vector<char>> v(n+1, vector<char>(m+1));
	map<char, int> mp;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>v[i][j];
			if (flag==0 && v[i][j]==r){
				start = {i, j};
				flag=1;
			}
		}
	}
	ii end=start;
	int p=start.ff, q=start.ss;
	while (v[p][q]==r){
		if (p==n)break;
		p++;
		if (v[p][q]==r){
			end.ff = p;
		}
	}
	p=start.ff;
	while (v[p][q]==r){
		if (q==m)break;
		q++;
		if (v[p][q]==r){
			end.ss = q;
		}
	}
/*	cout<<start.ff<<" "<<start.ss<<nl;
	cout<<end.ff<<" "<<end.ss<<nl;*/
	if (start.ff!=1)
		for (int i=start.ss;i<=min(n, end.ss);i++)
			if (v[start.ff-1][i]!='.')
				mp[v[start.ff-1][i]]=1;

	if(end.ff!=n)
		for (int i=start.ss;i<=min(n, end.ss);i++)
			if (v[end.ff+1][i]!='.')
				mp[v[end.ff+1][i]]=1;
	if (start.ss!=1)
		for (int i=start.ff;i<=min(m, end.ff);i++)
			if (v[i][start.ss-1]!='.')
				mp[v[i][start.ss-1]]=1;
	if (end.ss!=m)
		for (int i=start.ff;i<=min(m, end.ff);i++){
			if (v[i][end.ss+1]!='.'){
				mp[v[i][end.ss+1]]=1;
			}
		}
	int ans=0;
	for (auto i: mp)
		if (i.ss==1)
			ans++;
	cout<<ans<<nl;
}
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


int main(){
	nfs;
	int n;
	cin>>n;
	vvi dist(304, vi(304, 0));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>dist[i][j];
		}
	}
	int k, a, b, c;
	cin>>k;
	for (int p=0;p<k;p++){
		cin>>a>>b>>c;
		if (c<dist[a][b]){
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					dist[i][j] = Min(dist[i][a]+c+dist[b][j],
									 dist[i][b]+c+dist[a][j], dist[i][j]);
				}
			}
		}
		ll sum=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				sum+=dist[i][j];
			}
		}
		cout<<sum/2<<" ";
	}
	cout<<nl;
}
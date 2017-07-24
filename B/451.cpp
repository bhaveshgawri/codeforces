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
	int n;
	cin>>n;
	vi v(n+2);
	v[0]=-1;
	v[n+1]=inf;
	for (int i=1;i<=n;i++){
		cin>>v[i];
	}
	int i=1;
	while(i<=n-1 && v[i+1]>v[i])i++;
	int start = i;
	while(i<=n-1 && v[i+1]<v[i])i++;
	int end = i;
	int flag1=0, flag2=0,flag3=1;
	if (v[end]>v[start-1])flag1=1;
	if (v[end+1]>v[start])flag2=1;
	for (int i=end;i<n;i++){
		if (v[i+1]<v[i]){
			flag3=0;
			break;
		}
	}
	if (flag1&&flag2&&flag3)cout<<"yes"<<nl<<start<<" "<<end<<nl;
	else cout<<"no"<<nl;
}
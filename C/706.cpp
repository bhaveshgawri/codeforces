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
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

vector<string> vs(Max1);
vi cost(Max1);

void rec(int idx){
	if (idx<=1){
		return 0;
	}
	else if (idx==2){
		int ans=inf;
		if (vs[2]>vs[1])
			return 0;
		else if (reverse(all(s[1]))<s[2]){
			ans=min(ans, cost[1]);
		}
		else if ()
	}

}

int main(){
	nfs;
	int n;
	cin>>n;
	string s;
	int c;
	for (int i=1;i<=n;i++){
		cin>>c;
		cost[i]=c;
	}
	for (int i=1;i<=n;i++){
		cin>>s;
		vs[i]=s;
	}
	rec(n);
}
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

ii process(int n){
	int counter2=0, counter5=0;
	int temp = n;
	while(temp%2==0){
		temp/=2;
		counter2++;
	}
	while(n%5==0){
		n/=5;
		counter5++;
	}
	return {counter2, counter5};
}

void solve(){
	ll n;
	cin>>n;
	ll mat[n+1][n+1];
	vector<vector<II>> count(n+1, vector<II>(n+1, II(0ll, 0ll)));
	char ans[n+1][n+1];
	ii pt = {inf, inf};
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=n;j++){
			cin>>mat[i][j];
			if (mat[i][j]==0){
				pt = {i, j};
			}
		}
		mat[0][i]=mat[i][0]=INF;
		count[0][i].ff=count[0][i].ss=INF;
		count[i][0].ff=count[i][0].ss=INF;
	}

	if (pt.ff!=inf){
		cout<<1<<nl;
		for (int i=1;i<pt.ff;i++) cout<<"D";
		for (int i=1;i<pt.ss;i++) cout<<"R";
		for (int i=pt.ff;i<n;i++) cout<<"D";
		for (int i=pt.ss;i<n;i++) cout<<"R";
	}
	else{
		ii temp = process(mat[1][1]);
		count[1][1].ff+=temp.ff;
		count[1][1].ss+=temp.ss;

		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=n;j++){
				if (i==1 && j==1)continue;
				ii inc = process(mat[i][j]);
				count[i][j].ff+=inc.ff;
				count[i][j].ss+=inc.ss;
				
				ll zerou = min(count[i-1][j].ff, count[i-1][j].ss);
				ll zerol = min(count[i][j-1].ff, count[i][j-1].ss);
				if (zerol<zerou){
					count[i][j].ff += count[i][j-1].ff;
					count[i][j].ss += count[i][j-1].ss;
					ans[i][j] = 'R';	
				}
				else{
					count[i][j].ff += count[i-1][j].ff;
					count[i][j].ss += count[i-1][j].ss;
					ans[i][j] = 'D';
				}
			}
		}

		ans[1][1]='*';
		ll i=n, j=n;
		char ptr = ans[i][j];
		string s="";
		cout<<min(count[n][n].ff, count[n][n].ss)<<nl;
		while(ptr!='*'){
			s.pb(ptr);
			if (ptr=='D')i--;
			else if (ptr=='R')j--;
			ptr = ans[i][j];
		}
		reverse(all(s));
		cout<<s<<nl;
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
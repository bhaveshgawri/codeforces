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
	int n, m, k, t, p, q;
	cin>>n>>m>>k>>t;
	vvi holes(Max1);
	vector<char> starts_with(Max1);
	starts_with[1]='c';
	for (int i=0;i<k;i++){
		cin>>p>>q;
		holes[p].pb(q);
	}
	
	for (int i=2, hole_no=0;i<=n;i++){
		hole_no+=holes[i-1].size();
		int x = ((i-1)*m - hole_no)%3;
		if (x==0)starts_with[i] = 'c';
		else if (x==1)starts_with[i] = 'k';
		else if (x==2)starts_with[i] = 'g';
	}
	//for (int i=1;i<=n;i++)cout<<starts_with[i]<<nl;
	while(t--){
		cin>>p>>q;
		int hole_count=0, flag=0;
		for (int i: holes[p]){
			if (i<q){
				hole_count++;
			}
			else if (i==q){
				flag=1;
				break;
			}
		}
		if (flag==1){
			cout<<"Waste"<<nl;
		}
		else{
			q-=hole_count;
			q%=3;
			if (starts_with[p]=='c'){
				if (q==0)cout<<"Grapes"<<nl;
				else if (q==1)cout<<"Carrots"<<nl;
				else if (q==2)cout<<"Kiwis"<<nl;
			}else if (starts_with[p]=='k'){
				if (q==0)cout<<"Carrots"<<nl;
				else if (q==1)cout<<"Kiwis"<<nl;
				else if (q==2)cout<<"Grapes"<<nl;
			}else{
				if (q==0)cout<<"Kiwis"<<nl;
				else if (q==1)cout<<"Grapes"<<nl;
				else if (q==2)cout<<"Carrots"<<nl;
			}
		}
	}
}
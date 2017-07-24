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

vector<deque<int> > vd(Max1);
vector<string> vs;

void store(int k, int maxx){
	int i=0;
	int counter;
	while (i<maxx){
		counter=0;
		if (vd[i+1].size()>(ll)(k-1)*vd[i].size() && i!=maxx && i!=0){
			cout<<-1<<nl;
			exit(0);
		}
		for (int j: vd[i+1]){
			if (vd[i+1].size()>0)
				if (counter==(i==0?k:k-1)){
					counter=0; 
					vd[i].ppf();
				}
				if (vd[i].size()==0 && vd[i+1].size()!=0  && i!=maxx){
					cout<<-1<<nl;
					exit(0);
				}
				vs.pb(to_string(vd[i][0])+" "+to_string(j));
				counter++;
		}
		i++;
	}
}


int main(){
	nfs;
	int n, k, p, maxx=-1;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>p;
		maxx=max(p, maxx);
		vd[p].pb(i);
	}
	store(k, maxx);
	if (vd[0].size()!=1){
		cout<<-1<<nl;
	}
	else{
		cout<<vs.size()<<nl;
		for(string s: vs)
			cout<<s<<nl;
	}				
}
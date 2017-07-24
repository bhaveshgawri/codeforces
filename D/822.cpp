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

vi min_prime(5000004);
vl f(5000004);

int main(){
	nfs;
	int t, l, r;
	cin>>t>>l>>r;
	for (int i=2;i*i<=r;i++){
		if (min_prime[i]==0){
			for (int j=i*i;j<=r;j+=i){
				if (min_prime[j]==0){
					min_prime[j]=i;
				}
			}
		}
	}
	for (int i=2;i<=r;i++){
		if (min_prime[i]==0)
			min_prime[i]=i;
	}
	f[2]=1, f[3]=3;
	for (int i=4;i<=r;i++){
		if (i==min_prime[i]){
			f[i]=(ll)(((ll)(i-1)/2)*i);
			f[i]%=Mod;
			continue;
		}
		f[i]=(((i/min_prime[i])%Mod)*f[min_prime[i]]%Mod)%Mod+f[i/min_prime[i]]%Mod;
		if (f[i]>Mod)
			f[i]%=Mod;
	}
	cout<<nl;
	ll ans=0ll;
	ll tee=1ll;
	for (int i=l;i<=r;i++){
		ans+=(f[i]*tee);
		tee*=t;
		tee%=Mod;
		ans%=Mod;
	}
	cout<<ans<<nl;
}
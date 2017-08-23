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

string s;
vi v(26);
vi cache(1004, -1);
int max_len=1;

int ways(int start, int n){
	if (start == n-1 // n-1 when a,b,c,d + ways(n-1)#test2
	 || start == n){ // n when a,b, cde + ways(n) 	#test2
		return 1;
	}
	if (cache[start]!=-1)
		return cache[start];

	string t="";
	int lo=inf;
	int ans = 0;
	for (int i=start;i<n;i++){
		t+=s[i];
		lo = min(lo, v[s[i]-'a']);
		if (lo<t.length())
			break;
		max_len = max(max_len, (int)t.length());
		ans += ways(i+1, n);
		ans%=Mod;
	}
	return cache[start] = ans;
}

void solve(){
	int n;
	cin>>n;
	cin>>s;	
	for (int i=0;i<26;i++){
		cin>>v[i];
	}
	int ans = ways(0, n);
	cout<<ans<<nl<<max_len<<nl;
	int subs=0, lo=inf;
	string t="";
	for (int i=0;i<s.length();i++){
		t+=s[i];
		lo = min(lo, v[s[i]-'a']);
		if (lo<t.length()){
			t=t[t.length()-1];
			lo = v[s[i]-'a'];
			subs++;
		}
	}
	if (t!="")cout<<subs+1<<nl;
	else cout<<subs<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
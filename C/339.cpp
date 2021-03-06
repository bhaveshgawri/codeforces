#include <bits/stdc++.h>

#define gc         getchar
#define pc         putchar
// #define gc         getchar_unlocked
// #define pc         putchar_unlocked

#define ll         long long
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
//first element greater or equal to k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k

// fast i/o for integers
#define in2(a, b)        in(a), in(b)
#define in3(a, b, c)     in2(a, b), in(c)
#define in4(a, b, c, d)  in3(a, b, c), in(d)
#define out2(a, b)       out(a), out(b)
#define out3(a, b, c)    out2(a, b), out(c)
#define out4(a, b, c, d) out3(a, b, c), out(d)

template <typename T> bool in(T &n){
	n = 0;
	bool got = false, negative = false;
	char c = gc();
	while( c < '0' || c > '9'){if (c == '-') negative = true; c = gc();}
	while(c >= '0' && c <= '9'){got = true; n = n*10 + c-48; c = gc();}
	if(negative) n = ~(n-1);
	return got;
}
template <typename T> void out(T n, char seperator = ' '){
	if(n<0){pc('-'); n = -n;}
	if(!n) {pc('0'); pc(seperator); return;}
	char buff[22]; 
	int len = 0;
	while(n) buff[len++] = n%10+48,n/=10;
	for(int i=len-1;i>=0;i--) pc(buff[i]);
	pc(seperator);
}

#define inf      INT_MAX
#define INF      LLONG_MAX

#define ff       first
#define ss       second

using namespace  std;

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 4;

int M, odd_sum, eve_sum;
bool stop_rec;
vi v;
vi weights;

void calculate(int m, int last_weight, bool parity){
	if (stop_rec) return;
	if (m==M+1){
		if (((M&1) && (odd_sum > eve_sum)) || (!(M&1) && (odd_sum < eve_sum))){
			cout<<"YES"<<nl;
			for (int i: v)cout<<i<<" ";
				stop_rec = 1;
		}
	}
	for (int weight: weights){
		if (parity){
			if (weight!= last_weight && weight+odd_sum > eve_sum){
				v.pb(weight);
				odd_sum += weight;
				calculate(m+1, weight, !parity);
				odd_sum -= weight;
				v.ppb();
			}
		}
		else{
			if (weight!= last_weight && weight+eve_sum > odd_sum){
				v.pb(weight);
				eve_sum += weight;
				calculate(m+1, weight, !parity);
				eve_sum -= weight;
				v.ppb();
			}	
		}
	}
}

void solve(){
	string s;
	cin>>s;
	for (int i=1;i<=10;i++){
		if (s[i-1]=='1') weights.pb(i);
	}
	cin>>M;
	calculate(1, 0, 1);
	if (!stop_rec) cout<<"NO"<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
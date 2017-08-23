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

int isAvailable[11];

int find(int diff, int last){
	for (int i=diff+1;i<=10;i++){
		if (isAvailable[i] && i!=last)
			return i;
	}
	return -1;
}

void solve(){
	string s;
	cin>>s;
	for (int i=1;i<=10;i++){
		isAvailable[i] = s[i-1] - '0';
	}
	int m, one=0;
	cin>>m;
	if (m==1)one=1;
	for (int i=1;i<=10;i++){
		if (isAvailable[i]){
			int a = i, b = 0, diff, last = i, counter = 1; 
			int flag = 0, n = m;
			vi ans;
			ans.pb(i);
			if (one);
			else{
				n--;
				while(n--){
					diff = abs(a-b);
					int temp = find(diff, last);
					if (temp==-1 || (diff==0 && n>0 && last!=i)){
						flag = 1;
						break;
					}
					ans.pb(temp);
					last = temp;
					counter&1?b+=temp:a+=temp;
					counter++;
				}
			}
			if (flag==0){
				cout<<"YES"<<nl;
				for (int i: ans)cout<<i<<" ";
				cout<<nl;
				return;
			}
		}
	}
	cout<<"NO"<<nl;
}

int main(){
	nfs;
	no_step;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
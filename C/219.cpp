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

void solve(){
	int n, k;
	string s;
	cin>>n>>k;
	cin>>s;
	int changes = 0;
	int l = s.length();
	if (k==2){
		int ab=0, ba=0;
		for (int i=0;i<l;i++){
			if (i&1){
				ab += 'B' - s[i];
				ba += s[i] - 'A';
			}
			else{
				ab += s[i] - 'A';
				ba += 'B' - s[i];
			}
		}
		int flag;
		ab<ba ? flag=1 : flag = 0;
		if (flag){
			cout<<ab<<nl;
			while(l>1){
				cout<<"AB";
				l-=2;
			}
			if (l) cout<<"A"<<nl;
		}
		else{
			cout<<ba<<nl;
			while(l>1){
				cout<<"BA";
				l-=2;
			}
			if (l) cout<<"B"<<nl;
		}
	}
	else{
		for (int i=0;i<l-1;i++){
			if (s[i]==s[i+1]){
				int s_index = i;
				while (s[i]==s[i+1] && i<l-1) i++;
				
				int count = i-s_index+1;
				int loop_start = s_index;
				char c = (s[s_index]-65+1)%k;
				
				if (count&1) loop_start++;
				else{
					if (s_index == 0);
					else if (i == l-1) loop_start++;
					else if (s[s_index-1] == s[i+1]){
						if (c+65==s[s_index-1]){
							c+=1;
							c%=k;
						}
					}
					else if (s[s_index-1]==c+65) loop_start++;
				}
				c+=65;
				for (int j=loop_start;j<=i;j+=2){
					s[j] = c;
					changes++;
				}
			}
		}
		cout<<changes<<nl<<s<<nl;
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
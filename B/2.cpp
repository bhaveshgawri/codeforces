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
//first element greater or equal to k
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

int mat[1004][1004];
int mat2[1004][1004];
vvi ans2(1004, vi(1004, inf));
vvi ans5(1004, vi(1004, inf));
char ans2c[1004][1004];
char ans5c[1004][1004];
ii zero_pos;

ii two_five(int n){
	int two=0;
	int count2=0, count5=0;
	while(n%2==0){
		n /= 2;
		count2++;
	}
	while(n%5==0) {
		n /= 5;
		count5++;
	}
	return {count2, count5};
}

void solve(){
	int n;
	cin>>n;
	bool zero=false;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>mat[i][j];
			mat2[i][j] = mat[i][j];
			if (mat[i][j]==0){
				zero = true;
				mat[i][j]=10;
				zero_pos.ff = i, zero_pos.ss = j;
			}
		}
	}
	ans2[1][0] = ans2[0][1] = ans5[1][0] = ans5[0][1] = 0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			ii count = two_five(mat[i][j]);
			ans2[i][j] = min(ans2[i-1][j], ans2[i][j-1])+count.ff;
			ans2[i-1][j]<ans2[i][j-1] ? ans2c[i][j] = 'D' : ans2c[i][j] = 'R';
			ans5[i][j] = min(ans5[i-1][j], ans5[i][j-1])+count.ss;
			ans5[i-1][j]<ans5[i][j-1] ? ans5c[i][j] = 'D' : ans5c[i][j] = 'R';
		}
	}
	ans2c[1][1] = ans5c[1][1] = 'x';
	if (!zero || (zero && min(ans2[n][n], ans5[n][n])==0)){
		cout<<min(ans2[n][n], ans5[n][n])<<nl;
		vector<char> v;
		int i = n, j = n;
		if (ans2[n][n] < ans5[n][n]){
			while(ans2c[i][j] != 'x'){
				if (ans2c[i][j] == 'D') i--, v.pb('D');
				else if (ans2c[i][j] == 'R') j--, v.pb('R');
			}
		}
		else{
			while(ans5c[i][j] != 'x'){
				if (ans5c[i][j] == 'D') i--, v.pb('D');
				else if (ans5c[i][j] == 'R') j--, v.pb('R');
			}	
		}
		reverse(all(v));
		for (char c: v)cout<<c;
	}
	else if (zero && min(ans2[n][n], ans5[n][n])!=0){
		cout<<1<<nl;
		for (int i=1;i<zero_pos.ss;i++) cout<<"R";
		for (int i=1;i<n;i++) cout<<"D";
		for (int i=zero_pos.ss+1;i<=n;i++) cout<<"R";
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
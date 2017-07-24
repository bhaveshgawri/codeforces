#include <bits/stdc++.h>

#define ll      long long int

#define nl         "\n"
#define pb         push_back
#define ppb        pop_back
#define pf         push_front
#define ppf        pop_front
#define sz(x)      x.size()
#define all(x)     x.begin(), x.end()
#define Sort(x)    sort(all(x))
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

int main(){
	nfs;
	int n, check=0, count=0;
	cin>>n;
	int a[n][n];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>a[i][j];
			if (a[i][j]!=1)
				check++;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]!=1){
				int flag=0;
				for (int k=0;k<n;k++){
					for (int p=0;p<n;p++){
						if (k!=j && p!=i && a[i][k]+a[p][j]==a[i][j]){
							count++;
							flag=1;
							break;
						}
					}
					if (flag==1)
						break;
				}
			}
		}
	}
	if (check==count)
		cout<<"Yes"<<nl;
	else
		cout<<"No"<<nl;

}


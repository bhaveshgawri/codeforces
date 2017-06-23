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
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int Max1 = 1e5 + 4;
const int Max2 = 2e5 + 4;
const int Mod = 1e9 + 7;

vi lps(Max2, 0);

void find_lps(string s){
	int len_ps=0;
	lps[0]=0;
	int i=1;
	while(i<s.size()){
		if (s[i]==s[len_ps])
			lps[i++] = ++len_ps;
		else
			if(len_ps!=0)
				len_ps = lps[len_ps-1];
			else
				lps[i++]=0;
	}
}

int main(){
	nfs;
	string s;
	cin>>s;
	cout<<s.size()<<nl;
	find_lps(s);
	if (lps[s.size()-1]==0)
		cout<<"Just a legend"<<nl;
	else{
		int flag=0;
		for (int i=0;i<s.size()-1;i++){
			if (lps[i]==lps[s.size()-1]){
				for (int j=0;j<lps[i];j++){
					cout<<s[j];
				}
				cout<<nl;
				return 0;
			}
		}
		if (lps[lps[s.size()-1]-1]==0){
			cout<<"Just a legend"<<nl;
			return 0;
		}
		for (int i=0;i<lps[lps[s.size()-1]-1];i++){
			cout<<s[i];
		}
		cout<<nl;
	}
}
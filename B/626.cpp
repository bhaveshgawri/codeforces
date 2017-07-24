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
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<char, int> mp;
	for (char i: s){
		mp[i]++;
	}
	int count=0;
	for (ii i: mp)
		if (i.ss!=0)
			count++;
	if (count==3){
		cout<<"BGR"<<nl;
	}
	else if (count==2){
		if (mp['B']==0){
			if (mp['G']>=2 && mp['R']>=2)
				cout<<"BGR"<<nl;
			else if (mp['G']==1 && mp['R']==1)
				cout<<"B"<<nl;
			else{
				if (mp['G']==1){
					cout<<"BG"<<nl;
				}
				else{
					cout<<"BR"<<nl;
				}
			}
		}
		else if (mp['G']==0){
			if (mp['B']>=2 && mp['R']>=2)
				cout<<"BGR"<<nl;
			else if (mp['B']==1 && mp['R']==1)
				cout<<"G"<<nl;
			else{
				if (mp['B']==1){
					cout<<"BG"<<nl;
				}
				else{
					cout<<"GR"<<nl;
				}
			}
		}
		if (mp['R']==0){
			if (mp['G']>=2 && mp['B']>=2)
				cout<<"BGR"<<nl;
			else if (mp['G']==1 && mp['B']==1)
				cout<<"R"<<nl;
			else{
				if (mp['G']==1){
					cout<<"GR"<<nl;
				}
				else{
					cout<<"BR"<<nl;
				}
			}
		}
	}
	else{
		if (mp['R']!=0)cout<<"R"<<nl;
		else if (mp['G']!=0)cout<<"G"<<nl;
		else if (mp['B']!=0)cout<<"B"<<nl;
	}
}
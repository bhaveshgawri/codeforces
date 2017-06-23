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

#define f    first
#define s    second

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

int main(){
	nfs;
	string s;
	cin>>s;
	int digits = sz(s);
	if (digits==1)
		cout<<s<<nl;
	else{
		int count8=0, count9=0;
		for (int i=1;i<digits;i++){
			if (s[i]=='8')
				count8++;
			else if (s[i]=='9')
				count9++;
		}
		if (count9==digits-2 && count8==1 || count9==digits-1)
			cout<<s<<nl;
		else if (s[1]=='9'){
			int k=1;
			while(s[k]=='9')
				k++;
			for (int i=0;i<k-1;i++)
				cout<<s[i];
			cout<<s[k-1]-'1';
			for (int i=k;i<digits;i++)
				cout<<'9';
			cout<<nl;
		}
		else
			if (s[0]=='1'){
				for (int i=0;i<digits-1;i++)
					cout<<'9';
				cout<<nl;
			}
			else{
				for (int i=0;i<digits;i++)
					if (i==0)
						cout<<s[i]-'1';
					else
						cout<<'9';
				cout<<nl;
			}		
	}
}
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
#define mxe(a)          *max_element(all(a))
#define mne(a)          *min_element(all(a))

#define lb(x, k) lower_bound(all(x), k)-x.begin()
#define ub(x, k) upper_bound(all(x), k)-x.begin()

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

vi h(Max1), x(Max1), l(Max1), s(Max1);

bool rightPossible(int i){
	return x[i+1]-x[i]>h[i];
}
bool leftPossible(int i){
	return x[i]-x[i-1]>h[i];
}

int main(){
	nfs;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>x[i]>>h[i];
	}
	s[0]=0, l[0]=1;
	for (int i=1;i<n-1;i++){
		s[i]=l[i-1];
		//l[i]=max(leftPossible(i)?l[i-1]+1:s[i], rightPossible(i)?l[i-1]+1:s[i]);
		int a=s[i], b=s[i];
		if (leftPossible(i))
			a=l[i-1]+1;
		else if (rightPossible(i))
			b=l[i-1]+1, x[i]+=h[i];
		l[i]=max(a, b);
		//cout<<x[i]<<" "<<h[i]<<" "<<l[i]<<" "<<s[i]<<nl;
	}
	if (n>1)
		l[n-1]=l[n-2]+1;
	cout<<max(l[n-1], s[n-1])<<nl;
}
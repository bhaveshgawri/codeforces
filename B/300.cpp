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

vi selected(104);
vvi T(104);
vvi team(104);
set<int> s;

void select(int student, int number){
	if (!selected[student]){
		selected[student]=1;
		selected[student]=1;
		team[number].pb(student);
		for (int team_mate: T[student]){
			select(team_mate, number);
		}
	}
}

int main(){
	nfs;
	int n, m, p, q;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>p>>q;
		T[p].pb(q);
		T[q].pb(p);
		s.insert(p);
		s.insert(q);
	}
	int component=0;
	for (auto i: s)
		if (!selected[i])
			component++, select(i, component);
	if (n%3!=0){
		cout<<-1<<nl;
		return 0;
	}
	component = max(component, n/3);
	for (int i=1;i<=n;i++){
		if (selected[i]==0){
			for (int t=1;t<=component;t++){
				if (sz(team[t])<3){
					team[t].pb(i);
					selected[t]=1;
					break;
				}
			}
		}
	}
	for (int t=1;t<=component;t++)
		if (sz(team[t])!=3){
			cout<<-1<<nl;
			return 0;
		}
	for (int i=1;i<=component;i++){
		for (int j: team[i])
			cout<<j<<" ";
		cout<<nl;
	}
}
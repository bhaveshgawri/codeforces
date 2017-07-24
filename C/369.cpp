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

vvii D(Max1);
vi visited(Max1);
vi related(Max1);
vi ans;

int dfs(int node){
    visited[node]=1;
    related[node]=0;
    for (auto i: D[node]){
        if (visited[i.ff]==0){
            related[node] |= dfs(i.ff);
            if (i.ss==2 && related[i.ff]==0){
                related[i.ff]=1;
                ans.pb(i.ff);
            }
            related[node] |= related[i.ff];
        }
    }
    return related[node];
}

int main(){
    nfs;
    int n, p, q, t;
    cin>>n;
    for (int i=0;i<n-1;i++){
        cin>>p>>q>>t;
        D[p].pb({q, t});
        D[q].pb({p, t});
    }
    dfs(1);
    cout<<ans.size()<<nl;
    for (int i:ans)
        cout<<i<<" ";
    cout<<nl;
}
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

vector< vector< pair<ll, ll> > >G(100004);

void dijkstra(vector<ll>&distance, ll n, ll start){
	priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater <pair<ll, ll> > > Q;
	distance[start]=0;
	Q.push(make_pair(0, start));

	while(!Q.empty()){
		pair<ll, ll> top = Q.top();
		Q.pop();

		ll v = top.second;
		ll d = top.first;

		if (d<=distance[v]){
			for (auto it = G[v].begin();it!=G[v].end();++it){
				ll cost = it->first;
				ll v2 = it->second;
				if (distance[v2] > distance[v] + cost){
					distance[v2] = distance[v] + cost;
					Q.push(make_pair(distance[v2], v2));
				}
			}
		}
	}
	for (ll i=1;i<=n;i++){ 
		if (distance[i]==LLONG_MAX)
			cout<<-1<<" ";
		else
			cout<<distance[i]<<" ";
	}
}


int main(){
	ll n, q, s;
	cin>>n>>q>>s;
	vector<ll> distance(100004, LLONG_MAX);
	for (ll i=0;i<q;i++){
		ll t;
		cin>>t;
		if (t==1){
			ll v, u, w;
			cin>>v>>u>>w;
			G[v].push_back(make_pair(w, u));
		}
		else{
			ll v, l, r, w;
			cin>>v>>l>>r>>w;
			if (t==2)
				for (ll j=l;j<=r;j++)
					G[v].push_back(make_pair(w, j));
			else if(t==3)
				for (ll j=l;j<=r;j++)
					G[j].push_back(make_pair(w, v));
		}
	}
	dijkstra(distance, n, s);
}
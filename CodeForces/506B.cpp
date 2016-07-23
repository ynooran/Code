#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
using namespace std;
const int N = 2e5;
bool hasCycle, seen[N];
int n, m, mark[N];
vector<int> adj[N], dir[N], vc;
void cdfs(int v){
	seen[v] = true;
	vc.pb(v);
	for(int u : adj[v])
		if(!seen[u])
			cdfs(u);
}
void dfs(int v){
	mark[v] = 1;
	for(int u : dir[v])
		if(!mark[u])
			dfs(u);
		else if(mark[u] == 1)
			hasCycle = true;
	mark[v] = 2;
}
int main(){
	cin>>n>>m;
	int ans = n;
	FOR(i,0,m){
		int u,v;
		cin>>u>>v;
		dir[u].pb(v);
		adj[v].pb(u);
		adj[u].pb(v);
	}
	FOR(i,1,n+1)
		if(!mark[i]){
			vc.clear();
			cdfs(i);
			for(int v : vc)
				dfs(v);
			if(!hasCycle)
				ans--;
			hasCycle = false;
		}
	cout<<ans<<endl;
}

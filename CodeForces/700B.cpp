#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
using namespace std;
const int N = 2e5+10;
long long n, k, stk[N], ans;
vector<int> adj[N];
void dfs(int v, int p){
	for(int u : adj[v])
		if(u!=p){
			dfs(u,v);
			ans += min(stk[u],2*k-stk[u]);
			stk[v] += stk[u];
		}
}
int main(){
	cin>>n>>k;
	FOR(i,0,2*k){
		int u;
		cin>>u;
		stk[u] = 1;
	}
	FOR(j,0,n-1){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v),adj[v].pb(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
}

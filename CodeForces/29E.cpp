#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mk make_pair
using namespace std;
const int N = 505;
typedef long long ll;
typedef pair<pair<int,int>,bool> state;
vector<int> adj[N];
int n, m, dist[N][N][2], p, ans;
queue<state> Q;
state par[N][N][2];
void printPath(){
	vector<int> v1,v2;
	int a = n, b = 1;
	do{
		v1.pb(a);
		v2.pb(b);
		FOR(i,0,2){
			state tmp;
			tmp = par[a][b][i];
			a = tmp.first.first;
			b = tmp.first.second;
		}
	}while(ans--);
	for(int x : v2)
		cout<<x<<" ";
	cout<<"\n";
	for(int x : v1)
		cout<<x<<" ";
	cout<<endl;
}
void bfs(){
	while(!Q.empty()){
		state fr = Q.front();
		Q.pop();
		int a = fr.first.first, b = fr.first.second;
		bool t = fr.second;
		if(!t){
			for(int u : adj[a])
				if(dist[u][b][1] ==-1){
					dist[u][b][1] = dist[a][b][t];
					par[u][b][1] = fr;
					Q.push(mk(mk(u,b),true));
				}
		}
		else{
			for(int u : adj[b]){
				if(u == a || dist[a][u][0]!=-1)
					continue;
				dist[a][u][0] = dist[a][b][t] + 1;
				par[a][u][0] = fr;
				Q.push(mk(mk(a,u),false));
			}
		}
	}
}
int main(){
	memset(dist,-1,sizeof(dist));
	cin>>n>>m;
	dist[1][n][0] = 0;
	Q.push(mk(mk(1,n),false));
	while(m--){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v), adj[v].pb(u);
	}
	bfs();
	ans = dist[n][1][0];
	cout<<ans<<endl;
	if(ans != -1)
		printPath();
}

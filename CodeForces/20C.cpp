#include <iostream>
#include <queue>
#include <vector>
#define mk make_pair
#define pb push_back
#define pii pair <int,int>
const int MAX = 100100;
using namespace std;
vector <pii> adj[MAX];
int par[MAX];
priority_queue <pair<int,pii> >Q;
bool sure[MAX];
void print (int x)
{
	if(!x)
		return;
	print(par[x]);
	cout<<x<<" ";
}
int main()
{
	int n,m,a,b,w;
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b>>w;
		adj[a].pb(mk(b,w));
		adj[b].pb(mk(a,w));
	}
	Q.push(mk(0,mk(1,0)));
	while(!Q.empty())
	{
		int node = Q.top().second.first;
		int d = Q.top().first;
		int p = Q.top().second.second;
		Q.pop();
		if(sure[node])
			continue;
		par[node] = p;
		sure[node] = true;
		for(auto x : adj[node])
			if(!sure[x.first])
				Q.push(mk(d-x.second,mk(x.first,node)));
	}
	if(par[n])
		print(n);
	else
		cout<<"-1"<<endl;
}

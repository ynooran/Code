#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pii pair<int,int> 
#define mk make_pair
#define pb push_back
using namespace std;

const int MAX = 10001;
vector<pii> adj[MAX];
priority_queue <pii> Q;
bool seen[MAX];

int main()
{
	int n,m;
	long long ans=0;
	cin>>n>>m;
	while(m--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].pb(mk(-w,b));
		adj[b].pb(mk(-w,a));
	}
	Q.push(mk(0,1));
	while(!Q.empty())
	{
		int t,w;
		w = Q.top().first;
		t = Q.top().second;
		Q.pop();
		if(t[seen])
			continue;
		ans-= w;
		t[seen] = true;
		for(auto x: adj[t])
			Q.push(x);
	}
	cout<<ans<<endl;
}
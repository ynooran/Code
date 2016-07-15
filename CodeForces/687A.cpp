#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 1e5;
int n,m,color[MAX+1];
bool flag;
vector<int> e[MAX+1];
void dfs(int x, int c)
{
	color[x] = c;
	for(int v : e[x])
		if(!color[v])
			dfs(v,c^3);
		else if(color[v] == c)
			flag = true;
}
int main()
{
	cin>>n>>m;
	FOR(i,0,m)
	{
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	FOR(i,1,n+1)
		if(!color[i])
			dfs(i,1);
	if(flag)
		cout<<-1<<endl;
	else
	{
		vector<int> f,s;
		FOR(i,1,n+1)
			if(color[i]==1)
				f.push_back(i);
			else
				s.push_back(i);
		cout<<f.size()<<endl;
		for(int x : f)
			cout<<x<<" ";
		cout<<endl;
		cout<<s.size()<<endl;
		for(int x : s)
			cout<<x<<" ";
		cout<<endl;
	}
}

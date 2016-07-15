#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int MAX = 200001;
vector<int> day[MAX];
vector<pair<int,int> > m[MAX];
int n,deg[MAX],delta;
void dfs(int x, int par,int color)
{
	int c=0;
	for(pair<int,int> y : m[x])
	{
		if(y.first == par)
			continue;
		if(++c==color)
			c++;
		day[c].push_back(y.second);
		dfs(y.first,x,c);
	}
}
int main()
{
	cin>>n;
	FOR(i,1,n)
	{
		int j,k;
		cin>>j>>k;
		m[j].push_back(make_pair(k,i));
		m[k].push_back(make_pair(j,i));
		deg[j]++;deg[k]++;
	}
	delta = max_element(deg,deg+n+1) - deg;
	dfs(delta,0,0);
	cout<<deg[delta]<<endl;
	FOR(i,1,deg[delta]+1)
	{
		cout<<day[i].size()<<" ";
		for(int j : day[i])
			cout<<j<<" ";
		cout<<endl;
	}
}

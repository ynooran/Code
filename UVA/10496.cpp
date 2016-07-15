#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int n,perm[10];
bool seen[10];
pair<int,int> b[10],start;
int dist(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}
int ans(int ind)
{
	int ret= 1<<30;
	if(ind == n)
		return dist(b[perm[n-1]],b[0]);
	FOR(i,0,n)
	if(!seen[i])
	{
		int tmp = dist(b[i],b[perm[ind-1]]);
		perm[ind++]=i;
		seen[i] = true;
		tmp+= ans(ind--);
		ret = min(tmp,ret);
		seen[i] = false;
	}
	return ret;
}
int main()
{
	int w;
	cin>>w;
	while(w--)
	{
		FOR(i,0,2)
			cin>>n;
		cin>>b[0].first>>b[0].second;
		cin>>n;n++;
		seen[0] = 1;
		perm[0] = 0;
		FOR(i,1,n)
			cin>>b[i].first>>b[i].second;
		cout<<"The shortest path has length "<<ans(1)<<endl;
	}
}

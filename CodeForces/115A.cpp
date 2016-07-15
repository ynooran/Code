#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) cerr<<#x<<": "<<x<<' '
using namespace std;
int g[2010][2];
int f (int x)
{
	int &a = g[x][1];
	if(!a)
	{
		if(g[x][0]<0)
			a=1;
		else
			a=f(g[x][0]) +1;
	}
	return a;
}
int main()
{
	int n,ans=1;cin>>n;
	FOR(i,1,n+1)
		cin>>g[i][0];
	FOR(i,1,n+1)
		ans = max(f(i),ans);
	cout<<ans<<endl;
}

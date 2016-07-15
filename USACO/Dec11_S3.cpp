#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int dp[5010],x[5010],c[100010],n,m;
int main()
{
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	int n,m;
	cin>>n>>m;
	FOR(i,1,n+1)
		cin>>x[i];
	FOR(i,1,m+1)
		cin>>c[i];
	for(int i=m-1;i>=0;i--)
		c[i] = min(c[i+1],c[i]);
	sort(x,x+n+1);
	FOR(i,1,n+1)
	FOR(j,0,i)
		dp[i] = min(dp[i],dp[j] + c[x[i]-x[j+1]+1]);
	cout<<dp[n]<<endl;
}

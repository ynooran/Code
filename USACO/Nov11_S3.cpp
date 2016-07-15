#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int dp [10][10010],m,n,a[11];
int main()
{
	FOR(i,0,10)FOR(j,0,10010)dp[i][j]=10000000;
	cin>>n>>m;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,n)
	FOR(j,0,10010)
	FOR(d,1,101)
	{
		int cost = (d-a[i])*(d-a[i]);
		int r = j - d*d;
		if(r<0)
			continue;
		if(i)
			dp[i][j] = min(dp[i][j],cost + dp[i-1][r]);
		else if(!r)
			dp[i][j] = cost;
	}
	if(dp[n-1][m] > 1000000)
		cout<<"-1"<<endl;
	else
		cout<<dp[n-1][m]<<endl;
}

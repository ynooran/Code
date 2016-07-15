#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a,b,c, dp[4001], pos[4001];
int main()
{
	cin>>n>>a>>b>>c;
	pos[0] = true;
	FOR(i,1,n+1)
	{
		if(i>=a &&pos[i-a])
			dp[i] = dp[i-a],pos[i] = true;
		if(i>=b &&pos[i-b])
			dp[i] = max(dp[i], dp[i-b]), pos[i] = true;
		if(i>=c && pos[i-c])
			dp[i] = max(dp[i],dp[i-c]), pos[i] = true;
		dp[i] += 1;
	}
	cout<<dp[n]<<endl;
}

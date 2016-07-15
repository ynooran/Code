#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
const int N = 60, T = 800, K = 2300, M = 1000000007, delta = 55967;
unsigned int dp[N][T][K], n, t, k;
int32_t main()
{
	cin>>n>>t>>k;
	FOR(i,0,2)
			dp[0][i][0] = 1;
	FOR(i,1,n+1)
	{
		//Root is chosen
		FOR(t1,0,t+1)
			FOR(k1,0,k+1)
				FOR(t2,0,t+1-t1)
					FOR(k2,0,k-k1)
					{
						dp[i][t1+t2][k1+k2+1] += (dp[i-1][t1][k1]*dp[i-1][t2][k2])%M;
						dp[i][t1+t2][k1+k2+1] %= M;
					}
		//Root isn't chosen and one subtree has chosen leaves
		FOR(k1,0,k+1)
			FOR(t2,1,t+1)
				FOR(k2,0,k-k1+1)
				{
					dp[i][t2][k1+k2] += (2*((dp[i-1][0][k1]*dp[i-1][t2][k2])%M))%M;
					dp[i][t2][k1+k2] %= M;
				}
		//Root isn't chosen and no leaves are chosen either
		FOR(k1,0,k+1)
			FOR(k2,0,k+1-k1)
			{
				dp[i][0][k1+k2] += (dp[i-1][0][k1]*dp[i-1][0][k2])%M;
				dp[i][0][k1+k2] %=  M;
			}
	}
	cout<<dp[n][t][k]%delta<<endl;
}

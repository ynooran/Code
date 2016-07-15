#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 11471;
int dp[129][9][9][129];
int main()
{
	dp[1][1][1][1] = 1;
	FOR(n,2,129) FOR(l,1,9) FOR(k,l,9) FOR(m,1,n+1){
		if(l==1)
		{
			FOR(i,m+1,n+1)
				FOR(j,1,k+1)
				{
					dp[n][k][l][m] += dp[n-1][k][j][i-1];
					dp[n][k][l][m] %= delta;
				}
		}
		else 
			FOR(i,1,m)
			{
				dp[n][k][l][m] += dp[n-1][k][l-1][i];
				if(k==l)
					dp[n][k][l][m] += dp[n-1][k-1][k-1][i];
				dp[n][k][l][m] %= delta;
			}
	}
	cout<<dp[3][2][2][2]<<endl;
	int ans = 0;
	FOR(i,1,9)
		FOR(j,1,129)
		{
			ans += dp[128][8][i][j];
			ans %= delta;
		}
	cout<<ans<<endl;
}

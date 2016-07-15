#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 11471, MAX = 60, K = 3000;
int dp[MAX+1][K+1];
int main()
{
	FOR(i,1,K+1)
		dp[0][i] = 1;
	FOR(i,1,MAX+1)
		FOR(l,1,K+1)
			FOR(d,1,K+1)
				{
					int v = __gcd(l,d);
					dp[i][v] += dp[i-1][d]*dp[i-1][l];
					dp[i][v] %= delta;
				}
	cout<<dp[60][1]<<endl;
}


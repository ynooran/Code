#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int L = 1000,K=10;
int dp[L+1][L+1][K+1][2], n, m, k;
string s, t;
int main()
{
	cin>>n>>m>>k>>s>>t;
	FOR(i,1,n+1)
		FOR(j,1,m+1)
			FOR(l,1,k+1)
			{
				if(s[i-1] == t[j-1])
					dp[i][j][l][1] = 1 + max(dp[i-1][j-1][l-1][0],dp[i-1][j-1][l][1]);	
				dp[i][j][l][0] = max(dp[i][j][l][1], max(dp[i-1][j][l][0], dp[i][j-1][l][0]));
			}
	cout<<dp[n][m][k][0]<<endl;
}

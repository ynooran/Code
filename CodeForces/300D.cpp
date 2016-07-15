#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
const int delta = 7340033;
int n,q,k;
using namespace std;
int dp[35][1001], tmp[1000];
int cut (int x)
{
	if(x&1)
		return cut(x/2)+1;
	return 0;
}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>q;
	FOR(i,1,35)
		dp[i][1] = 1;
	FOR(i,1,34)
		FOR(c,0,4)
		{
			FOR(k,0,1001)
				tmp[k] = 0;
			FOR(j,1,1001)
				FOR(aj,j+1,1001)
				{
					tmp[aj] += (dp[i+1][aj - j]*dp[i][j])%delta;
					tmp[aj] %= delta;
				}
			FOR(k,1,1001)
			{
				dp[i+1][k] += tmp[k];
				dp[i+1][k] %= delta;
			}
		}
	FOR(i,0,35)
		dp[i][0] = 1;
	while(q--)
	{
		cin>>n>>k;
		if( (1<<(cut(n))) > n )
			cout<<dp[cut(n)-1][k]<<endl;
		
		else	
			cout<<dp[cut(n)][k]<<endl;
		

	}
}

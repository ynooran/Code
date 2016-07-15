#include <cstdio>
#include<iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 4010;
int n,k,e[MAX],b[MAX],dp[MAX][MAX];
int main()
{
	int ans=0;
	cin>>n>>k;
	FOR(i,1,n+1)
	{
		scanf("%d",&b[i]);
		scanf("%d",&e[i]);
		e[i] += b[i];
		e[i]--;
		b[i]--;
	}
	FOR(i,1,n+1)
		FOR(j,0,k+1)
		{
			int d = dp[i-1][j] - b[i];
			if(d<0)
				d=0;
			dp[i][j] = e[i] + d;
			if(j && dp[i-1][j-1] < dp[i][j])
				dp[i][j] = dp[i-1][j-1];
		}
	FOR(i,0,n)
		ans = max(ans, b[i+1] - dp[i][k]);
	ans = max(ans,86400 - dp[n][k]);
	cout<<ans<<endl;
}

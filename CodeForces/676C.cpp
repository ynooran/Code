#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int MAX = 1e5+1;
int n,k,dp[MAX],ans;
int main()
{
	cin>>n>>k;
	FOR(i,1,n+1)
	{
		char tmp;
		cin>>tmp;
		dp[i] = dp[i-1] + (tmp=='b');
	}
	FOR(i,1,n+1)
	{
		int l = 1, m, h = n+1;
		while(h-l>1)
		{
			m = (h+l)/2;
			if(dp[m] - dp[i-1] <= k)
				l = m;
			else
				h = m;
		}
		ans = max(ans, l - i + 1);
	}
	FOR(i,1,n+1)
	{
		int l=1, m, h = n+1;
		while(h-l>1)
		{
			m = (h+l)/2;
			if( (m-dp[m]) - ( (i-1) - dp[i-1]) <=k)
				l = m;
			else
				h = m;
		}
		ans = max(ans, l - i + 1);
	}
	cout<<ans<<endl;
}

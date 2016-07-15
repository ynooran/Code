#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 1e6, delta = 11471;
int dp[MAX+1];
int main()
{
	dp[1] = 1;
	FOR(i,1,MAX+1)
		for(int j=2*i; j<=MAX; j+=i)
		{
			dp[j] += dp[i];
			dp[j] %= delta;
		}
	long long sum = 0;
	FOR(i,1,MAX+1)
	{
		sum+=dp[i];
		sum%=delta;
	}
	cout<<sum<<endl;
}


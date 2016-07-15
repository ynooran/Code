#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int K = 1e6, delta = 11471;
int dp[K+1];
long long tp60;
int pow(int a, long long b)
{
	a %= delta;
	if(!b)
		return 1;
	if(b&1)
		return (a*pow(a,b-1))%delta;
	int ret = pow(a,b/2);
	return (ret*ret)%delta;
}
int main()
{
	tp60 = 1;
	FOR(i,0,60)
		tp60*=2;
	for(int i = K; i>0; i--)
	{
		dp[i] = pow(K/i,tp60 % (delta-1));
		for(int j = 2*i; j<=K; j+=i)
		{
			dp[i] -= dp[j];
			if(dp[i]<0)
				dp[i]+=delta;
		}
	}
	cout<<dp[1]<<endl;
}

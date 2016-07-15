#include <iostream>
#include <vector>
#define FOR(i,a,b) for(long long i=a; i<b; i++)
using namespace std;
const long long delta=10243,N =10*1000*1000+1;
vector<int> primes;
bool nPrime[N];
int dp[N];
int max()
{
	int ret=0;
	FOR(i,0,N)
		if(dp[i]>dp[ret])
			ret = i;
	return ret;
}
int main()
{
	FOR(i,2,N)
	if(!nPrime[i])
	{
		primes.push_back(i);
		for(long long j=i*i;j<N;j+=i)
			nPrime[j] = true;
	}
	dp[1] = 1;
	FOR(i,2,N)
	for(long long x : primes)
	{
		if(x*x>i)
		{
			dp[i]=2;
			break;
		}
		if(i%x==0)
		{
			int c = i;
			while(c%x==0)
			{
				c/=x;
				dp[i]++;
			}
			++dp[i]*=dp[c];
			break;
		}
	}
	FOR(i,0,3)
		dp[max()]=0;
	cout<<max()%delta<<endl;
}

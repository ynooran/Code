#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int N = 1389000, delta = 10267;
bool primes[N+1];
int dp[N+1],sum;
int main()
{
	primes[0] = primes[1] = 1;
	for(int i=2; i*i<=N; i++)
		if(!primes[i])
			for(int j = i*i; j<=N; j+=i)
				primes[j] = 1;
	FOR(i,1,N+1)
	{
		dp[i]+=dp[i/10];
		if(i%10 == 2)
			dp[i]++;
		if(i%2)
		{
			for(int j=10; 10*i>=j ; j*=10)
			{
				int tmp = i%j;
				if(tmp>=(j/10) && !primes[tmp])
					dp[i]++;
			}
		}
		dp[i]%= delta;
		sum+= dp[i];
		sum%= delta;
	}
	cout<<sum<<endl;
}

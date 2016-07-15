#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 781817;
const int MAX = 1e4;
long long sum;
vector<int> primes;
int dp[1300][MAX+1];
bool isPrime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}

int main()
{
	primes.push_back(0);
	FOR(i,2,MAX)
		if(isPrime(i))
			primes.push_back(i);
	cout<<primes.size()<<endl;
	FOR(i,0,1300)
		dp[i][0] = 1;
	FOR(i,1,primes.size())
		FOR(j,2,MAX+1)
		{
			int num=0;
			while(num*primes[i]<=j && num<primes[i])
			{
				dp[i][j] += dp[i-1][j-num*primes[i]];
				dp[i][j]%=delta;
				num++;
			}
		}
	FOR(i,2,MAX+1)
	{
		sum+=dp[primes.size()-1][i];
		sum%=delta;
	}
	cout<<sum<<endl;
}

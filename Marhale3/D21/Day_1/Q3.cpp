#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10039;
bool sieve[2*delta+101];
vector<int> primes;
int M=1;
int d (int x, int y)
{
	if(x==y)
		return 0;
	if(x>y)
		return 1+d(x/2,y);
	return 1+d(x,y/2);
}
int main()
{
	for(int i=2; i*i<= 2*delta+100; i++)
		if(!sieve[i])
			for(int j = i*i; j<= 2*delta+100; j+=i)
				sieve[j] = true;
	FOR(i,2,delta+1)
		if(!sieve[i])
			primes.push_back(i);
	FOR(i,0,primes.size())
		FOR(j,i+1,primes.size())
			if(!sieve[primes[i]+primes[j]+1])
			{
				M*= d(primes[i],primes[j]);
				M%= delta;
			}
	cout<<M<<endl;
}

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000, delta = 781817;
long long p[MAX+1], ans;
vector<int> primes;
bool sieve[MAX+1];
int main()
{
	for(int i=2; i*i<=MAX; i++)
		for(int j = i*i; !sieve [i] && j<=MAX; j+=i)
				sieve[j] = true;
	for(int i=2;i<=MAX;i++)
		if(!sieve[i])
			primes.push_back(i);
	for(int i=primes.size()-1; i>=0; i--)
		for(int j = 1; primes[i]*j<=MAX; j++)
			if(!p[j*primes[i]])
				p[j*primes[i]] = primes[i];
	ans = 2;
	for(int i= 5; i<=MAX; i++){
		if(p[i]*p[i]<=i)
			ans += 2;
		else
			ans++;
		ans %= delta;
	}
	cout<<ans<<endl;
}

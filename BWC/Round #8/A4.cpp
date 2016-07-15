#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
const ll MAX = 1e11, delta = 781817;
ll ans, ex;
vector<ll> primes;
bitset<100000000001> sieve;
int main()
{
	for(ll i=2; i*i<=MAX; i++){
		cerr<<i<<endl;
		for(ll j = i*i; !sieve [i] && j<=MAX; j+=i){
				sieve[j] = true;
		}
	}
	for(ll i=2;i<=MAX;i++)
		if(!sieve[i])
			primes.push_back(i);
	cerr<<"HELLO!"<<endl;
	ans = 2*(MAX - 2);
	for(auto x : primes)
	{
		ll i=0;
		while(i*x<=MAX)i++;
		ans-=min(x,i)-1;
		ans+=delta;
		ans%=delta;
	}
	cout<<ans<<endl;
}

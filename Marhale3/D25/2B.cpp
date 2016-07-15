#include <iostream>
#include <vector>
#define dbug(x) #x<<" "<<(x)<<" "
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
using namespace std;
const int MAX = 1e6, M = 55967;
int ans;
bool sieve[MAX+1];
vector<int> primes,V;
int32_t main()
{
	for(int i=2; i*i<=MAX; i++)
		if(!sieve[i])
			for(int j = i*i; j<=MAX;j+=i)
				sieve[j] = true;
	FOR(i,2,MAX+1)
		if(!sieve[i])
			primes.push_back(i);
	for(auto a : primes)
	{
		int sgf = min(a, MAX/a);
		int kids = upper_bound(primes.begin(),primes.end(),sgf) - primes.begin();
		V.push_back(kids);
	}
	sort(V.begin(),V.end());
	FOR(i,1,V.size())
		V[i] += V[i-1];
	FOR(i,1,250001)
	{
		int ind = upper_bound(V.begin(),V.end(),i) - V.begin() - 1;
		//cerr<<dbug(i)<<dbug(V[ind])<<(ind+1)<<endl;
		int ak = ((ind+1)*V[ind])%M;
		ak *= ak;
		ans = (ak + ans)%M;
	}
	cout<<ans<<endl;
}

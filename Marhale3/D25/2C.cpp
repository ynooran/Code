#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
using namespace std;
const int MAX = 1e6, M = 55967;
int ans;
bool sieve[MAX+1];
vector<int> primes,V;
vector<pair<int,int> > ziba;
int32_t main()
{
	for(int i=2; i*i<=MAX; i++)
		if(!sieve[i])
			for(int j = i*i; j<=MAX;j+=i)
				sieve[j] = true;
	FOR(i,2,MAX+1)
		if(!sieve[i])
			primes.push_back(i);
	for(int a : primes)
	{
		int b = a*a;
		if(b<=MAX)
		{
			if(b*a<=MAX)
			{
				ziba.push_back(make_pair(b,a-1));
				if(b*b<=MAX)
				{
					ziba.push_back(make_pair(b*a,a-1));
					ziba.push_back(make_pair(b*b,a));
				}
				else
					ziba.push_back(make_pair(b*a,a));

			}
			else
			{
				ziba.push_back(make_pair(b,a));
			}
		}
	}
	FOR(i,0,primes.size())
		FOR(j,i+1,primes.size())
			if(primes[i]*primes[j]<=MAX)
				ziba.push_back(make_pair(primes[i]*primes[j],primes[i]));
	for(auto a : ziba)
	{
		int sgf = min(a.second, MAX/a.first);
		V.push_back(upper_bound(primes.begin(),primes.end(),sgf) - primes.begin());
	}
	sort(V.begin(),V.end());
	FOR(i,1,V.size())
		V[i] += V[i-1];
	FOR(i,1,250001)
	{
		int ind = upper_bound(V.begin(),V.end(),i) - V.begin();
		int ak = ((ind)*V[ind-1])%M;
		ak *= ak;
		ans = (ak + ans)%M;
	}
	cout<<ans<<endl;
}

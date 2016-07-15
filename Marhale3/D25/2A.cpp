#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
using namespace std;
const int MAX = 40000, M = 55967;
int ans;
bool sieve[MAX+1];
vector<int> primes,V;
vector<pair<int,int> > sq;
int32_t main()
{
	for(int i=2; i*i<=MAX; i++)
		if(!sieve[i])
		{
			sq.push_back(make_pair(i*i,i));
			for(int j = i*i; j<=MAX;j+=i)
				sieve[j] = true;
		}
	FOR(i,2,MAX+1)
		if(!sieve[i])
			primes.push_back(i);
	for(auto a : sq)
	{
		int sgf = min(a.second, MAX/a.first);
		V.push_back(upper_bound(primes.begin(),primes.end(),sgf) - primes.begin());
	}
	sort(V.begin(),V.end());
	FOR(i,1,V.size())
		V[i] += V[i-1];
	FOR(i,1,151)
	{
		int ind = upper_bound(V.begin(),V.end(),i) - V.begin() - 1;
		int ak = (ind+1)*V[ind];
		ak *= ak;
		ans = (ak + ans)%M;
	}
	cout<<ans<<endl;
}

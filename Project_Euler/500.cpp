#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define int long long
using namespace std;
const int M = 500500507, MAX = 500500, SM = 8e6;
bool sieve[SM];
vector<int> primes;
priority_queue<pair<int, int>,vector<pair<int,int> >, greater<pair<int,int> > > Q;
int32_t main()
{
	FOR(i,2,SM)
		if(!sieve[i])
		{
			primes.push_back(i);
			if(primes.size() == MAX)
				break;
			for(int j = i*i; j<SM; j+=i)
				sieve[j] = true;
		}
	FOR(i,0,MAX)
		Q.push(make_pair(primes[i]*primes[i],primes[i]));
	int ind = MAX - 1;
	while(Q.top().first<primes[ind])
	{
		Q.push(make_pair(Q.top().first*Q.top().first,Q.top().second));
		Q.pop();
		ind--;
	}
	int p = 1;
	while(!Q.empty())
	{
		if(Q.top().second<=primes[ind])
		{
			p*=(Q.top().first/Q.top().second)%M;
			p %= M;
		}
		Q.pop();
	}
	cout<<p<<endl;
}

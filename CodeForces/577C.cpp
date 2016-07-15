#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
bool sieve[1100];
vector<int> primes,answer;
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
		if(!sieve[i])
		{
			primes.push_back(i);
			for(int j=i*i; j<=n; j+=i)
				sieve[j] = true;
		}
	for(const int x : primes)
		for(int j = x; j<=n; j*=x)
			answer.push_back(j);
	cout<<answer.size()<<endl;
	for(const int x : answer)
		cout<<x<<" ";
}

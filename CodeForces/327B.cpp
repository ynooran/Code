#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 1e7;
int n, a[100001];
bool seen[MAX + 1];
vector<int> primes;
int main()
{
	cin>>n;
	for(int i=2; i*i<=MAX; i++)
		if(!seen[i])
			for(int j = i*i; j<=MAX; j+=i)
				seen[j] = true;
	FOR(i,2,MAX+1)
		if(!seen[i])
			primes.push_back(i);
	FOR(i,0,n)
		cout<<primes[i]<<" ";
	cout<<endl;
}


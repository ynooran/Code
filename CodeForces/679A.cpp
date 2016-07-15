#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
bool sieve[50],comp;
vector<int> primes;
string s;
bool div(int x)
{
	if(x > 100)
		return false;
	cout<<x<<endl;
	cin>>s;
	if(s[0] == 'y')
		return 1;
	return 0;
}
int main()
{
	FOR(i,2,50)
		if(!sieve[i])
		{
			primes.push_back(i);
			for(int j=i*i;j<50;j+=i)
				sieve[j] = true;
		}
	for(int i=0; primes[i]<15; i++)
	{
		if(div(primes[i]))
		{
			if(div(primes[i]*primes[i]))
				comp = true;
			for(int j=i+1;j<primes.size() && primes[i]*primes[j]<=100; j++)
				if(div(primes[j]))
					comp = true;
			break;
		}
	}
	if(comp)
		cout<<"composite"<<endl;
	else
		cout<<"prime"<<endl;
}

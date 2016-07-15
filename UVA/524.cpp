#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
bool notPrime[32],seen[17];
int n,perm[17];
void solve(int ind) 
{
	if(ind==n && !notPrime[perm[n]+1])
	{
		FOR(i,1,n+1)
			cout<<perm[i]<<" ";
		cout<<endl;
	}
	if(ind==n)
		return;
	FOR(i,1,n+1)
	if(!seen[i] && !notPrime[perm[ind] + i])
	{
		perm[++ind]=i;
		seen[i] = true;
		solve(ind--);
		seen[i] = false;
	}
}
int main()
{
	for(int i=2;i*i<32;i++)
	if(!notPrime[i])
	for(int j=i*i;j<32;j+=i)
		notPrime[j] = true;
	seen[1] = perm[1] = 1;
	cin>>n;
	solve(1);
}

#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
long long n,k,c[1000000];
long long lcm (long long a, long long b)
{
	long long ret = a*b;
	return ret/__gcd(a,b);
}
int main()
{
	cin>>n>>k;
	FOR(i,0,n)
		scanf("%lld",c+i);
	long long L = __gcd(c[0],k);
	FOR(i,1,n)
	{
		L = lcm(L,c[i]);
		L = __gcd(L,k);
	}
	cout<<(L==k ? "YES":"NO")<<endl;
}

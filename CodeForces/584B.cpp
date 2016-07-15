#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long int delta = 1000000007;
long long int p ( int j )
{
	long long int r=1,t=1;
	while(j--)
	{
		r*=27;
		r%= delta;
		t*=7;
		t%= delta;
	}
	return (delta + r - t)%delta;
}
int main()
{
	int n;cin>>n;
	cout<<p(n)<<endl;
}

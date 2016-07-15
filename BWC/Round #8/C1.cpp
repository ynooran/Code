#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const long long delta = 781817;
const long long MAX = 1395*2016;
long long a[4];
int main()
{
	a[0] = 1;
	FOR(i,0,MAX)
	{
		long long z = a[0];
		a[0] += a[1] + a[2];
		a[0] %= delta;
		a[3] += a[2];
		a[3] %= delta;
		a[2] = a[1];
		a[1] = z;
	}
	cout<<(a[0])%delta<<endl;
}


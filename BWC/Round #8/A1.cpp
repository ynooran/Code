#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const long long delta = 781817;
const long long MAX  =  1e14;
long long sum;
int main()
{
	sum = MAX/2;
	sum%=delta;
	sum*=(MAX+1);
	sum%=delta;
	sum-=5;
	sum+=delta;
	sum%=delta;
	cout<<sum<<endl;
}


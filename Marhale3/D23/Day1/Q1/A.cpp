#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10567;
int f (int y)
{
	if(!y)
		return 1;
	if(y%2)
		return (3*f(y/2))%delta;
	return (2*f(y/2))%delta;
}
int main()
{
	int n = delta + 3; 
	int s=0;
	FOR(i,1,n)
	{
		s+=f(i);
		s%=delta;
	}
	int sum = 0;
	FOR(i,1,n)
	{
		sum+=i;
		sum%=delta;
	}
	cout<<(sum*s)%delta<<endl;
}

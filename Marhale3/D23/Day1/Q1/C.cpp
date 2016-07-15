#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10567;
int f[10003];
int pow(int a, int b)
{
	a%=delta;
	if(!b)
		return 1;
	if(b%2)
		return (a*pow(a,b-1))%delta;
	int tmp = pow(a,b/2);
	return (tmp*tmp)%delta;
}
int main()
{
	f[0] = 0;
	FOR(i,1,10001)
		f[i] = (5*f[i-1] + 3)%delta;cout<<"hi\n"<<endl;
	int ans = ((f[10000] * pow(2,9999))%delta)*(pow(2,10000)-1);
	ans%=delta;
	cout<<ans<<endl;
}

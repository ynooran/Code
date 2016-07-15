#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int N = 1390, delta = 10091;
int log(int x)
{
	if(x==1)
		return 0;
	return 1 + log(x/2);
}
int main()
{
	long long M = 1;
	for(int i = 1; i<=N; i+=2)
	{
		M*=(log(N/i) + 1);
		M%=delta;
	}
	cout<<M<<endl;
}

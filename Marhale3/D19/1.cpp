#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int delta = 10243;
int main()
{
	long long a=1;
	FOR(i,0,2010)
		a*=1388,a%=1000000;
	long long b=1;
	while(a)
	{
		b*=a%10;
		a/=10;
	}
	cout<<b%delta<<endl;
}


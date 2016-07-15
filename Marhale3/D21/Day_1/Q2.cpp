#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int prime[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
const int delta = 10039;
long long best = 1;
void ans (int ind, int max_power, long long num, int divs)
{
	if(divs >= 2011)
	{
		best = num;
		return;
	}
	long long c = 1;
	for(int i=1; i<=max_power; i++)
	{
		c*= prime[ind];
		if(num*c>= best)
			return;
		ans(ind+1, i, num*c, divs*(i+1));
	}
}
int main()
{
	FOR(i,0,11)
		best*= prime[i];
	ans(0,2010,1,1);
	cout<<best%delta<<endl;
}

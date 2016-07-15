#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, g;
int gcd (int a, int b)
{
	if(!a)
		return b;
	return gcd(b%a,a);
}
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		g = gcd(g,tmp);
	}
	cout<<g*n<<endl;
}

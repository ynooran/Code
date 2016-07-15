#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int x, y, a,b;
int main()
{
	cin>>x>>y;
	a = 7 - max(x,y);
	b = 6;
	int g = __gcd(a,b);
	cout<<a/g<<"/"<<b/g<<endl;
}


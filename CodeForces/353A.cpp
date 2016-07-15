#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
bool gd;
int n, a,b;
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		int x,y;
		cin>>x>>y;
		x&=1;
		y&=1;
		a^=x;
		b^=y;
		if(x^y)
			gd = true;
	}
	if(a && b)
		cout<<(gd ? 1 : -1)<<endl;
	else if(!a && !b)
		cout<<0<<endl;
	else
		cout<<-1<<endl;
}


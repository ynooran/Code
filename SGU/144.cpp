#include <iostream>
#include <iomanip>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	int x,y,d;
	double z;
	cin>>x>>y>>z;
	d = y - x;
	z/=60;
	cerr<<z<<endl;
	if(z>=d)
		cout<<1<<endl;
	else
	{
		double r =1 - z/(double)d;
		cout<<setprecision(7)<<1-r*r<<endl;
	}
}


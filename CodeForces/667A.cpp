#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long double d,h,v,e;
int main()
{
	cin>>d>>h>>v>>e;
	long double area = M_PI * d * d / 4;
	long double diff  = v - area*e;
	if(diff<=0)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		long double time = (h*area)/diff;
		cout<<time<<endl;
	}
}


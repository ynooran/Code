#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int xy,xd,yy,yd;
int main()
{
	cin>>xy>>yy>>xd>>yd;
	cout<<max(abs(xy-xd),abs(yy-yd))<<endl;
}

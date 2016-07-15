#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int x[2],y[2],ans;
int main()
{
	char a;
	cin>>a;
	x[0] = a-'a';
	cin>>a;
	y[0] = a-'a';
	cin>>a;
	x[1] = a-'a';
	cin>>a;
	y[1] = a-'a';
	ans = max(abs(x[0]-x[1]),abs(y[0]-y[1]));
	cout<<ans<<endl;
	FOR(i,0,ans)
	{
		if(x[0] > x[1])
		{
			cout<<"L";
			x[0]--;
		}
		else if(x[0]<x[1])
		{
			cout<<"R";
			x[0]++;
		}
		if(y[0] > y[1])
		{
			cout<<"D";
			y[0]--;
		}
		else if(y[0]<y[1])
		{
			cout<<"U";
			y[0]++;
		}
		cout<<endl;
	}
}

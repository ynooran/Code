#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,x,y,ans;
pair <int,int> o[1000000];
int main()
{
	cin>>n;
	FOR(i,0,n)
		cin>>o[i].first>>o[i].second;
	sort(o,o+n);
	FOR(i,0,n)
	{
		if(o[i].first>y)
		{
			x = y;
			y = o[i].second;
			ans++;
		}
		else if(o[i].first>x)
			y = min(y,o[i].second);
	}
	cout<<ans<<endl;
}


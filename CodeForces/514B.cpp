#include <iostream>
#include <set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int n, x[1001],y[1001];
set<pair<int,int> > m;
int main()
{
	cin>>n>>x[0]>>y[0];
	FOR(i,1,n+1)
	{
		cin>>x[i]>>y[i];
		x[i] -=x[0];
		y[i] -=y[0];
		if(x[i] && y[i])
		{
			int g = __gcd(x[i],y[i]);
			m.insert(make_pair(x[i]/g,y[i]/g));
		}
		else if(x[i])
			m.insert(make_pair(1,0));
		else if(y[i])
			m.insert(make_pair(0,1));
	}
	cout<<(m.size() ? m.size():1)<<endl;
}

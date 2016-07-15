#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, c, t, ans;
vector<int> V;
int main()
{
	cin>>n>>t>>c;
	V.push_back(0);
	FOR(i,1,n+1)
	{
		int tmp;
		cin>>tmp;
		if(tmp>t)
			V.push_back(i);
	}
	V.push_back(n+1);
	FOR(i,1,V.size())
	{
		int tans = V[i] - V[i-1] -c;
		if(tans>0)
			ans+=tans;
	}
	cout<<ans<<endl;
}

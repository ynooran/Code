#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int n, c, stall[100005];
bool isGood(int dist)
{
	int cur = stall[0];
	int numCows = 1;
	FOR(i,1,n)
	{
		if(stall[i] - cur >= dist)
		{
			numCows++;
			cur = stall[i];
		}
	}
	return (numCows>=c);
}
int bSearch(int low, int high)
{
	if(low+1 == high)
		return low;
	int mid = (low+high)/2;
	if(isGood(mid))
		return bSearch(mid,high);
	else
		return bSearch(low,mid);
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>c;
		FOR(i,0,n)
			cin>>stall[i];
		sort(stall,stall+n);
		int MAX = (stall[n-1] - stall[0])/(c-1);
		cout<<bSearch(0,MAX+1)<<endl;
	}
}

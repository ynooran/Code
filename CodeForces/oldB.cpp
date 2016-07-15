#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int ecells[4],fcells[4];
int main()
{
	int n;
	cin>>n>>fcells[0]>>fcells[3]>>fcells[1]>>fcells[2];
	int sum = fcells[0] + fcells[3];
	FOR(i,1,4)
	{
		ecells[i] = sum - (fcells[i] + fcells[i-1]);
	}
	FOR(i,0,4)
		cerr<<dbug(ecells[i])<<endl;
	sort(ecells,ecells+4);
	int k = ecells[3] - ecells[0];
	k = n - k;
	if(k<0)
		k=0;
	k*=n;
	cout<<k<<endl;
}

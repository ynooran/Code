#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 1e9 + 7;
int n, x[20];
int main()
{
	cin>>x[1]>>x[2]>>n;
	n = (n-3)%6 + 3;
	FOR(i,3,n+1)
	       x[i] = x[i-1] - x[i-2];
	while(x[n]<0)
		x[n]+=delta;
	cout<<x[n]%delta<<endl;	
}


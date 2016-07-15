#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
long long seq[100100],q[100100],f[100100];
const int delta = 1000000007;
long long d(long long a){return a%delta;}
int main()
{
	long long n,x,a,b;
	cin>>n>>x>>f[1]>>f[2]>>a>>b;
	FOR(i,0,n)
		cin>>seq[i+1];
	FOR(i,3,n+10)
		f[i] =d( d(a*f[i-2]) + d(b*f[i-1]) );
	while(x--)
	{
		int l,r;
		cin>>l>>r;
		q[l]=d(q[l] + f[1]);
		q[l+1]=d(q[l+1]+f[2]-f[1]);
		q[r+1]=d(q[r+1]-f[r-l+2]);
		q[r+2]=d(q[r+2]-f[r-l+1]);
	}
	FOR(i,2,n+2)
		q[i] =d(q[i] + d(a*q[i-2]) + d(b*q[i-1]));
	FOR(i,0,n)
		cout<<d(seq[i+1] + q[i+1])<<" ";
}

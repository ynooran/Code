#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n,m;
long long num[2][5],sum;
int main()
{
	cin>>n>>m;
	num[0][0] = n/5;
	num[1][0] = m/5;
	sum+=num[0][0]*num[1][0];
	FOR(i,1,5)
	{
		num[0][i] = (n+5-i)/5;
		num[1][i] = (m+5-i)/5;
	}
	FOR(i,1,5)
		sum += num[0][i]*num[1][5-i];
	cout<<sum<<endl;
}

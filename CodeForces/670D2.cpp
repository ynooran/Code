#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX1= 200000, MAX2 = 1000*1000*1000;
int n,k;
int a[MAX1],b[MAX1];

bool good(int x)
{
	long long sum=0;
	FOR(i,0,n)
	{
		long long dif = (long long)a[i]*x - b[i];
		if(dif>0)
			sum+=dif;
		if(sum>k)
			return false;
	}
	return true;
}
int main()
{
	cin>>n>>k;
	FOR(i,0,n)
		cin>>a[i];

	FOR(i,0,n)
		cin>>b[i];
	int mid,low=0,high=2*MAX2+1;
	while(low<high-1)
	{
		mid = low + (high-low)/2;
		if(good(mid))
			low = mid;
		else
			high = mid;
	}
	cout<<low<<endl;
}

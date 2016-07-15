#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n,l,a[1000];
bool isGood(long double x)
{
	long double end=0;
	FOR(i,0,n)
	{
		if(end+x<a[i])
			return false;
		end = a[i]+x;
	}
	if(end<l)
		return false;
	return true;
}
int main()
{
	cin>>n>>l;
	FOR(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	long double mid,low = 0, high = l+1;
	while(high-low>=1e-9)
	{
		mid = low + (high-low)/2;
		if(isGood(mid))
			high = mid;
		else
			low = mid;
	}
	cout<<fixed;
	cout.precision(10);
	cout<<high<<endl;
}

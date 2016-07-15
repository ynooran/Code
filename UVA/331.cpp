#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a[5];
int ans()
{
	int ret=0;
	FOR(i,0,n-1)
	if(a[i]>a[i+1])
	{
		swap(a[i],a[i+1]);
		ret+=ans();
		swap(a[i],a[i+1]);
	}
	if(!ret)
		ret++;
	return ret;
}
int main()
{
	int i=0;
	while(++i)
	{
		cin>>n;
		if(!n)
			break;
		FOR(i,0,n)
			cin>>a[i];
		int t=0;
		if(!is_sorted(a,a+n))
			t = ans();
		cout<<"There are "<<t
		<<" swap maps for input data set "<<i<<'.'<<endl;
	}
}

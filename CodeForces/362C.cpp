#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a[5000],ans;
int num()
{
	int ret = 0;
	for (int i = 1; i < n; i = i + 1)
	{
		int j = i; 
		while (j > 0 && a[j] < a[j - 1])
		{
			ret++;
			swap(a[j], a[j - 1]);
			j = j - 1;
		}
	}
	return ret;
}
int main()
{
	ans = 1000000000;
	cin>>n;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,n)
		FOR(j,i+1,n)
		{
			swap(a[i],a[j]);
			ans = min(ans,num());
			swap(a[i],a[j]);
		}
	cout<<ans<<endl;
}

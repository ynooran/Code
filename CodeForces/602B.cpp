#include <iostream>
using namespace std;
int n,a[100000];
int main() {
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	int i=0,j=0,mx=0,mn=0,ans=1;
	while(j<n)
	{
		while(a[mx]-a[mn]<2&&j<=n)
		{
			if(a[j]>=a[mx])
				mx = j;
			if(a[j]<=a[mn])
				mn = j;
			j++;
		}
		ans = max(ans,j-1-i);
		if(a[j-1]==a[mx])
			i = mn+1,mn++;
		else
			i = mx+1,mx++;
	}
	cout<<ans<<endl;
	return 0;
}

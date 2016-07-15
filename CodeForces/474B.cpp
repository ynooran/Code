#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a[100001],m,s[100001];
int main()
{
	cin>>n;
	FOR(i,1,n+1)
	{
		cin>>a[i];
		s[i] = s[i-1] + a[i];
	}
	cin>>m;
	while(m--)
	{
		int q;
		cin>>q;
		int low=0,mid,high = n;
		while(high-low>1)
		{
			mid = (high+low)/2;
			if(q<=s[mid])
				high = mid;
			else
				low = mid;
		}
		cout<<high<<endl;
	}
}

#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int N = 2e5;
int a[N],b[N], n;
int ans(int l, int h)
{
	if(h-l==1)
		return 0;
	int m = l + (h-l)/2;
	int ret = ans(l,m) + ans(m,h);
	int ind1 = l, ind2 = m;
	FOR(i,l,h)
	{
		if(ind1<m  && (a[ind1]<a[ind2] || ind2==h) )
			b[i] = a[ind1++];
		else
		{
			b[i] = a[ind2++];
			ret += m-ind1;
		}
	}
	FOR(i,l,h)
		a[i] = b[i];
	return ret;

}
int32_t main(){
	cin>>n;
	FOR(i,0,n)
		cin>>a[i];
	cout<<ans(0,n)<<endl;
	FOR(i,0,n)
		cout<<a[i]<<" ";
	printf("\n");
}

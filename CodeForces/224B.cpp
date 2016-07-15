#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,k,l,r,t,array[110000];
int b[110000];
int main()
{
	cin>>n>>k;
	int l=1;
	FOR(i,1,n+1)
	{
		cin>>array[i];
		const int tmp = array[i];
		if(!b[tmp])
			k--;
		b[tmp]++;
		if(!k)
		{
			r = i;
			break;
		}

	}
	if(!r)
		r=l=-1;
	else
		FOR(i,1,n+1)
			if(!(--b[array[i]]))
			{
				l = i;
				break;
			}
	cout<<l<<" "<<r;
}

#include <iostream>
#include <bitset>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
bitset<110000> a,b;
int array[110000];
int main()
{
	int n,it=0;cin>>n;
	FOR(i,1,n+1)
	{
		cin>>array[i];
		if(array[i]>n || a[array[i]])
			b[i] = true;
		else
			a[array[i]] = true;
	}
	FOR(i,1,n+1)
	{
		if(!b[i])
			cout<<array[i]<<" ";
		else
		{
			while(a[++it]);
			cout<<it<<" ";
		}
	}
}

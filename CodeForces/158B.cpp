#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int a[4];
int main()
{
	int n,answer=0;
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		a[tmp-1]++;
	}
	answer+= min(a[2],a[0]);
	a[2]-=answer;
	a[0]-=answer;
	answer+=a[2];
	answer+=a[3];
	answer+=a[1]/2;
	if(a[1]%=2)
	{
		a[0]-=2;
		answer++;
	}
	if(a[0]>0)
	{
		int x = a[0]/4;
		if(a[0]%4)
			x++;
		answer+=x;
	}
	cout<<answer<<endl;
}

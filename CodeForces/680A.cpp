#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int c[101],tmp,sum,ind;
int main()
{
	FOR(i,0,5)
	{
		cin>>tmp;
		c[tmp]++;
		sum+=tmp;
	}
	FOR(i,1,101)
	{
		if(i*min(3,c[i])>=ind*min(3,c[ind]) && c[i]>1)
			ind = i;
	}
	if(c[ind]>1)
		sum-=ind*min(c[ind],3);
	cout<<sum<<endl;
}

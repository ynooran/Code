#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 1e5;
int n,a[MAX];
int main()
{
	cin>>n;
	FOR(i,0,n)
		scanf("%d",a+i);
	sort(a,a+n);
	int i = 1, j = 0;
	while(j<n)
	{
		while(a[j]<i && j<n)
			j++;
		if(j<n)
			i++,j++;
	}
	cout<<i<<endl;
}

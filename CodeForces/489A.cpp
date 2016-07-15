#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a[3000];
int main()
{
	cin>>n;
	FOR(i,0,n)
		cin>>a[i];
	cout<<n-1<<endl;
	FOR(i,0,n-1)
	{
		int ind = min_element(a+i,a+n) - a;
		cout<<i<<" "<<ind<<endl;
		swap(a[ind],a[i]);
	}
}


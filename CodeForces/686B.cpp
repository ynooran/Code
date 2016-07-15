#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a[100];
int main()
{
	cin>>n;
	FOR(i,0,n)
		cin>>a[i];
	FOR(i,0,n)
		FOR(j,0,n-1)
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				cout<<j+1<<" "<<j+2<<endl;
			}
}


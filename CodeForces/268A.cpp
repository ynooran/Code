#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a[30][2];
int main()
{
	int ans=0;
	int n;cin>>n;
	FOR(i,0,n)
		cin>>a[i][0]>>a[i][1];
	FOR(i,0,n)
		FOR(j,0,n)
			if(abs(i-j)&&a[i][0]==a[j][1])
				ans++;
	cout<<ans<<endl;	
}

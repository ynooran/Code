#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n, ans, a[300000];
int main()
{
	cin>>n;
	FOR(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	FOR(i,1,n+1)
		ans += abs(a[i-1] - i);
	cout<<ans<<endl;
}

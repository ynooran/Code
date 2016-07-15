#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n,t,a[100001], s[100001], ans;
int main()
{
	cin>>n>>t;
	FOR(i,1,n+1){
		cin>>a[i];
		s[i] = a[i] + s[i-1];
	}
	long long j = 0;
	FOR(i,0,n)
	{
		while(s[j] - s[i] <= t && j<=n)
			j++;
		j--;
		ans = max(ans,j-i);
	}
	cout<<ans<<endl;
}

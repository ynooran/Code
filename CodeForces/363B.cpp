#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,k,s[150001],ans;
int main()
{
	cin>>n>>k;
	FOR(i,1,n+1)
	{
		cin>>s[i];
		s[i]+=s[i-1];
	}
	ans = k;
	FOR(i,k,n+1)
		if(s[i]-s[i-k]<s[ans]-s[ans-k])
			ans = i;
	cout<<ans-k+1<<endl;
}

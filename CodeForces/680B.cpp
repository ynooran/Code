#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a,t[101],ans;
int main()
{
	cin>>n>>a;
	FOR(i,1,n+1)
		cin>>t[i];
	FOR(i,1,n+1)
		if(t[i] && (2*a-i<1 || 2*a-i>n || t[2*a-i]))
			ans++;
	cout<<ans<<endl;
}


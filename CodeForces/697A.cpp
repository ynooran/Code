#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
int t,x,s;
int32_t main()
{
	cin>>t>>s>>x;
	while(x>t+s+1)
		x -= s;
	if(x == t || x==t+s || x==t+s+1 || x==t+2*s)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}


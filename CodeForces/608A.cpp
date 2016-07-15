#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,s;
int main()
{
	cin>>n>>s;
	FOR(i,0,n)
	{
		int a,b;
		cin>>a>>b;
		s = max(s,a+b);
	}
	cout<<s<<endl;
}


#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans=0;
	while(n)
	{
		if(n%2)
		{
			n--;
			ans++;
		}
		else
			n/=2;
	}
	cout<<ans<<endl;
}


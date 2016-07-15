#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	int n,t;
	cin>>n>>t;
	if(t==10)
		if(n==1)
			cout<<"-1"<<endl;
		else
		{
			cout<<1;
			while(--n)
				cout<<0;
			cout<<endl;
		}
	else
		while(n--)
			cout<<t;
}


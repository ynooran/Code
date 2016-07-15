#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long l,k,i;
int main()
{
	cin>>k>>l;
	for(i=-1;l!=1;i++)
		if(l%k)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else
			l/=k;
	cout<<"YES\n"<<i<<endl;
}


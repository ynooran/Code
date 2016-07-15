#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long a,b,c,d;
bool ans;
int main()
{
	cin>>a>>b>>c;
	d = b-a;
	if(!c)
	{
		if(d)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	else
	{
		if((d%c==0) && d*c>=0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

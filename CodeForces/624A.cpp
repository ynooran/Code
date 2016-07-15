#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long double d,L,v1,v2, ans;
int main()
{
	cout.precision(15);
	cin>>d>>L>>v1>>v2;
	ans = (L-d)/(v1+v2);
	if(ans>0)
		cout<<ans<<endl;
	else
		cout<<0<<endl;
}


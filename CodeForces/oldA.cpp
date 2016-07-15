#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	while((b-a)*c>0)
	 b -= c;
	if(a==b)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

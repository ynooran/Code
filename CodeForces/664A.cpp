#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
string a,b;
int main()
{
	cin>>a>>b;
	if(a==b)
		cout<<a<<endl;
	else
		cout<<1<<endl;
}


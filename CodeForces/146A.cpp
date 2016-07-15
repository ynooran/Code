#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n;
string s;
bool ans ()
{
	int a=0, b=0;
	FOR(i,0,n/2)
		if(s[i] == '4')
			a+=4;
		else if(s[i] == '7')
			a+=7;
		else
			return false;
	FOR(i,n/2,n)
		if(s[i] == '4')
			b+=4;
		else if(s[i] == '7')
			b+=7;
		else
			return false;
	return a==b;
}
int main()
{
	cin>>n;
	cin>>s;
	cout<<(ans() ? "YES":"NO")<<endl;
}

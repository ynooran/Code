#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a,b,l,m,h;
int main()
{
	cin>>a>>b;
	h = (a+b)*6,l = 0;
	while(h-l>1)
	{
		m = (h+l)/2;
 		((m/3>=b) && (m/2>=a) && (m/3 + m/2 - m/6 >= a+b) ? h : l) = m;
	}
	cout<<h<<endl;
}


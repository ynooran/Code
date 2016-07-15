#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int a,b,c,ab,bc,ca,ans;
int main()
{
	cin>>ab>>bc>>ca;
	a = sqrt((ab*ca)/bc) + 0.1;
	b = sqrt((bc*ab)/ca) + 0.1;
	c = sqrt((ca*bc)/ab) + 0.1;
	ans = 4*(a+b+c);
	cout<<ans<<endl;
}


#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long l,m,a[11],b,c[11],d,x,y;
int main()
{
	cin>>l>>b;
	for(int i=l-1;i>=0;i--)
		cin>>a[i];
	cin>>m>>d;
	for(int i = m-1; i>=0; i--)
		cin>>c[i];
	x = y = 1;
	FOR(i,0,l)
	{
		a[i]*=x;
		x*=b;
	}
	FOR(i,0,m)
	{
		c[i]*=y;
		y*=d;
	}
	b=d=0;
	FOR(i,0,l)
		b+=a[i];
	FOR(i,0,m)
		d+=c[i];
	if(b<d)
		cout<<"<\n";
	else if (b>d)
		cout<<">\n";
	else
		cout<<"=\n";
}

#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long p,h1,a1,x1,y1,h2,a2,x2,y2,ans,c,x;
void f1(){
	h1 = (x1*h1+y1)%p;
}
void f2(){
	h2 = (x2*h2+y2)%p;
}
int main()
{
	cin>>p>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
	FOR(i,0,p)
	{
		ans++;
		f1();
		f2();
		if(h1 == a1)
			break;
	}
	if(h1 == a1)
	{
		if(h2 == a2)
			cout<<ans<<endl;
		else
		{
			FOR(i,0,p)
			{
				c++;
				f1();
				if(h1 == a1)
					break;
			}
			if(h1==a1)
			{
				long long shib=1, arz=0;
				FOR(i,0,c)
				{
					shib*=x2;
					shib%=p;
					arz = (arz*x2 + y2)%p;
				}
				FOR(i,0,p)
				{
					x++;
					h2 = (h2*shib + arz)%p;
					if(h2 == a2)
						break;
				}
				if(h2 == a2)
					cout<<ans + c*x<<endl;
				else
					cout<<-1<<endl;
			}
			else
				cout<<-1<<endl;
		}
	}
	else
		cout<<-1<<endl;

}

#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	int a[5];FOR(i,0,5)cin>>a[i];
	long long ans=0;
	double l = (double)a[1]/(double)a[3];
	double m = (double)a[2]/(double)a[4];
	int j = l>m ? 1:2;
	const int  w1 =a[5-j],w2=a[j+2],h1=a[1+(j%2)],h2=a[j];
	int dd = a[0] + w1;
	if(w2>a[0])
		cout<<1ll*(a[0]/w1)*h1<<endl;
	else if(w2 == a[0])
		cout<<1ll*h2<<endl;
	else
	{
		FOR(i,0,w2)
		{
			dd -=w1;
			if(dd<0)
				break;
			int d = dd/w2;
			long long tmp = 1ll*i*h1 + 1ll*d*h2;
			if(tmp>ans)
				ans=tmp;
		}
		cout<<ans<<endl;
	}
}

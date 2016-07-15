#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	int a,b,c,d;cin>>a>>b>>c>>d;
	int x,y;
	FOR(i,0,a)
	{
		int tmp;cin>>tmp;
		if(c==i+1)
			x=tmp;
	}
	FOR(j,0,b)
	{
		int tmp;cin>>tmp;
		if(b-d == j)
			y = tmp;
	}
	cout<<(x<y ? "YES":"NO")<<endl;
}


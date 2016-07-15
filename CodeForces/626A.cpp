#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n, ans;
char a[200];

int main()
{
	cin>>n;
	cin>>a;
	FOR(i,0,n)
		FOR(j,i+1,n)
		{
			int U=0, L=0;
			FOR(l,i,j+1)
			{
				switch(a[l])
				{
					case 'U' : U++;	break;
					case 'D' : U--;	break;
					case 'L' : L++; break;
					case 'R' : L--;
				}
			}
			if(U==0 && L==0)
				ans++,cerr<<i<<" "<<j<<endl;
		}
	cout<<ans<<endl;
}


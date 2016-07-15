#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,row[100],column[100];

int main()
{
	cin>>n;
	FOR(i,0,n)
		FOR(j,0,n)
		{
			char tmp;
			cin>>tmp;
			if(tmp!='.')
			{
				row[i]++;
				column[j]++;
			}
		}
	int ans=0;
	FOR(i,0,n)
	{
		ans+= (row[i]*(row[i]-1))/2;
		ans+=(column[i]*(column[i]-1))/2;
	}
	cout<<ans<<endl;
}

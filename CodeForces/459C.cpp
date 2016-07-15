#include <iostream>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define error(x) cerr<<#x<<" = "<<x<<" "
using namespace std;
int students[1100][1100];
int main()
{
	bool flag=true;
	int n,k,d,tmp=1;
	cin>>n>>k>>d;
	for(int i=0;i<d && flag;i++)
	{
		tmp*=k;
		if(tmp>= n)
			flag=false;
	}
	if( flag )
		cout<<"-1 \n";
	else
	{
		FOR(i,1,n)
		{
			int tmp = 1;
			FOR(j,0,d)
			{
				students[i][j] = students[i-1][j] + tmp;
				if(students[i][j] >= k)
					students[i][j] = 0;
				else
					tmp = 0;
			}
		}
		FOR(i,0,d)
		{
			FOR(j,0,n)
				cout<<students[j][i] + 1<<' ';
			cout<<endl;
		}
	}
}

#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,m, ans, d[] = {1,2,1,0};
char a[9][9], b[9][9];
void bt(int x)
{
	if(x>ans)
	{
		ans = x;
		FOR(i,0,n)
			FOR(j,0,m)
				b[i][j] = a[i][j];
	}
	if(!(m*n/5-x))
		return;
	FOR(i,0,n)
		FOR(j,0,m)
			FOR(l,0,4)
			if(a[i][j] == '.')
			{
				int top = i - d[l];
				int bottom = i + d[(l+2)%4];
				int left = j - d[(l+3)%4];
				int right = j + d[(l+1)%4];
				if(top>=0 && bottom<n && right<m && left>=0)
				{
					bool okay = true;
					for(int v = top; v<=bottom && okay; v++)
						if(a[v][j] != '.')
							okay = false;
					for(int h = left; h<=right && okay; h++)
						if(a[i][h] !='.')
							okay = false;
					if(okay)
					{
						FOR(v, top, bottom+1)
							a[v][j] = 'A' + x;
						FOR(h, left, right+1)
							a[i][h] = 'A' + x;
						bt(x+1);
						FOR(v, top, bottom+1)
							a[v][j] = '.';
						FOR(h, left, right+1)
							a[i][h] = '.';
					}
				}	
			}
}
int main()
{
	cin>>n>>m;
	FOR(i,0,n)
		FOR(j,0,m)
			a[i][j]=b[i][j]='.';
	bt(0);
	cout<<ans<<endl;
	FOR(i,0,n){
		FOR(j,0,m)
			cout<<b[i][j];
		cout<<endl;
	}
}

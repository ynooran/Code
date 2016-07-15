#include <iostream>
#include <queue>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 1e9;
int n,mxp,a[1000];
queue<int> Q;
int gcd(int x, int y)
{
	if(!x)
		return y;
	return gcd(y%x,x);
}
int main()
{
	mxp = 999999937;
	cin>>n;
	FOR(i,0,n)
		cin>>a[i];
	Q.push(a[0]);
	FOR(i,1,n)
	{
		int g = gcd(a[i],a[i-1]);
		if(g>1)
		{	
			if(g==mxp)
				Q.push(2);
			else
				Q.push(mxp);
		}
		Q.push(a[i]);
	}
	cout<<Q.size()-n<<endl;
	while(!Q.empty())
	{
		cout<<Q.front()<<" ";
		Q.pop();
	}
	cout<<endl;
}

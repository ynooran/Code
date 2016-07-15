#include <iostream>
#include <queue>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
priority_queue<int> Q;
int n, m, ans;
int main()
{
	cin>>n>>m;
	FOR(i,1,n)
	{
		int tmp;
		cin>>tmp;
		Q.push(tmp);
	}
	while(m<=Q.top())
	{
		int tmp = Q.top();
		ans++;
		m++;
		Q.pop();
		Q.push(tmp-1);
	}
	cout<<ans<<endl;
}

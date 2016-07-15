#include <iostream>
#include <queue>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int n, k, tmp, ans;
queue<int> ea, eb;
int main()
{
	cin>>n>>k;
	FOR(i,0,k)
	{
		cin>>tmp;
		ea.push(tmp);
	}
	cin>>k;
	FOR(i,0,k)
	{
		cin>>tmp;
		eb.push(tmp);
	}
	FOR(i,1,40000000)
	{
		int a = ea.front(), b = eb.front();
		ea.pop(), eb.pop();
		if(a>b)
			ea.push(b),ea.push(a);
		else
			eb.push(a),eb.push(b);
		if(eb.empty() || ea.empty())
		{
			ans = i;
			break;
		}
	}
	if(ans)
		cout<<ans<<" "<<(eb.empty() ? 1: 2)<<endl;
	else
		cout<<-1<<endl;
}

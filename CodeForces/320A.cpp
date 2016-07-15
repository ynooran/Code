#include <iostream>
#include <queue>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
queue<int> Q;
int n;
bool ans()
{
	while(!Q.empty())
	{
		int num4s=0;
		if(Q.front() == 1)
		{
			Q.pop();
			continue;
		}
		else if(Q.front() != 4)
			return false;
		else
			while(Q.front() == 4)
			{
				num4s++;
				Q.pop();
			}
		if(num4s>2 || Q.front()!=1)
			return false;
		Q.pop();
	}
	return true;
}
int main()
{
	cin>>n;
	while(n)
	{
		Q.push(n%10);
		n/=10;
	}	
	cout<<(ans() ? "YES":"NO")<<endl;
}

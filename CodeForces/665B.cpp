#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,m,k,t;
vector<int> row;
void update(int x)
{
	vector<int> tmp;
	tmp.push_back(x);
	FOR(i,0,k)
	{
		if(row[i] == x)
			t+=i+1;
		else
			tmp.push_back(row[i]);
	}
	row = tmp;
}
int main()
{
	cin>>n>>m>>k;
	n*=m;
	FOR(i,0,k)
	{
		int tmp;
		cin>>tmp;
		row.push_back(tmp);
	}
	while(n--)
	{
		int tmp;
		cin>>tmp;
		update(tmp);
	}
	cout<<t<<endl;
}

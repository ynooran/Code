#include <iostream>
#include <fstream>
#include <queue>
#include<algorithm>
#include<vector>
#define dbug(x) x
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
priority_queue<int> B1,E1;
priority_queue<int, vector<int>, greater<int> > B2,E2;
bool b[100001];
int main()
{
	ifstream fin("cardgame.in");
	ofstream fout("cardgame.out");
	int n;
	fin>>n;
	FOR(i,0,n/2)
	{
		int a;
		fin>>a;
		E1.push(a);
		b[a] = true;
	}
	FOR(i,0,n/2)
	{
		int a;
		fin>>a;
		E2.push(a);
		b[a] = true;
	}
	vector<int> V;
	FOR(i,1,2*n+1)
	if(!b[i])
		V.push_back(i);
	sort(V.begin(),V.end());
	FOR(i,0,n/2)
	{
		B1.push(V.back());
		V.pop_back();
	}
	FOR(i,0,n/2)
	{
		B2.push(V.back());
		V.pop_back();
	}
	int ans=0;
	while(!E1.empty())
	{
		if(E1.top()<B1.top())
		{
			B1.pop();
			ans++;
		}
		E1.pop();
	}
	while(!E2.empty())
	{
		if(E2.top()>B2.top())
		{
			B2.pop();
			ans++;
		}
		E2.pop();
	}
	fout<<ans<<endl;
}

#include <iostream>
#include <vector>
#include <unordered_set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
using namespace std;
const int MAX = 1e5+10;
int  par[MAX], nm[MAX], n;
double stime[MAX];
vector<int> kids[MAX];
void dfsnm(int v)
{
	for(int k : kids[v])
	{
		dfsnm(k);
		nm[v] += 1 + nm[k];
	}
}
void calc(int v)
{
	unordered_set<int> S, Q;
	S.insert(0);
	for(int k : kids[v])
		for(int x : S)
			
}
int32_t main()
{
	cin>>n;
	par[1] = 1;
	FOR(i,2,n+1)
	{
		cin>>par[i];
		kids[par[i]].push_back(i);
	}
	dfsnm(1);
	stime[1] = 1;
	calc(1);
	FOR(i,1,n+1)
		cout<<stime[i]<<" ";
	cout<<endl;
}

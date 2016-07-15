#include <iostream>
#include <vector>
#include <map>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int id[20000];
map <int,int> mp[5];
bool comp (int a, int b) {
	int tmp = 0;
	FOR(i,0,5)
		tmp+=(mp[i][a]<mp[i][b]);
	return tmp>2;
}
int main()
{
	int n;
	cin>>n;
	FOR(i,0,5)
		FOR(j,0,n)
		{
			cin>>id[j];
			mp[i][id[j]] = j;
		}
	sort(id,id+n,comp);
	FOR(i,0,n)
		cout<<id[i]<<endl;
}

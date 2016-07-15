/*
ID: ynooran1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define mk make_pair
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int main()
{
	ofstream fout("milk2.out");
	ifstream fin ("milk2.in");
	pair<int,bool> farmers[10001];
	int n;fin>>n;
	FOR(i,0,n)
	{
		int a,b;fin>>a>>b;
		farmers[2*i] = mk(a,0);
		farmers[2*i+1]=mk(b,1);
	}
	sort(farmers,farmers+2*n);
	int men=0,index1=0,index2=0,fans1=0,fans2=0;
	FOR(i,0,2*n)
	{
		if(farmers[i].second)
			men--;
		else
			men++;
		if(men==1 && !farmers[i].second)
		{
			if(i)
			fans2=max(fans2,farmers[i].first-index2);
			index1=farmers[i].first;
		}
		if(!men)
		{
			fans1=max(fans1,farmers[i].first-index1);
			index2=farmers[i].first;
		}
				
	}
	fout<<fans1<<" "<<fans2<<endl;
}

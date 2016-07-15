#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
pair<int,int> interval[2];
int main()
{
	ifstream fin("paint.in");
	ofstream fout("paint.out");
	fin>>interval[0].first>>interval[0].second
	>>interval[1].first>>interval[1].second;
	if(interval[0]>interval[1])
		swap(interval[0],interval[1]);
	if(interval[1].second<=interval[0].second)
		fout<<interval[0].second-interval[0].first;
	else if(interval[1].first <= interval[0].second)
		fout<<interval[1].second-interval[0].first;
	else
		fout<<interval[0].second + interval[1].second
			- interval[1].first - interval[0].first;
}


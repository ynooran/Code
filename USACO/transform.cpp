/*
ID: ynooran1
PROG: transform
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
	ofstream fout("transform.out");
	ifstream fin ("transform.in");
	int n;
	char a[10][10],b[10][10];
	FOR(i,0,n)
		FOR(j,0,n)
		cin>>a[i][j];
	if(one())cout<<1<<endl;
	else if(two())cout<<2<<endl;
	else if(three())cout<<3<<endl;
	else if(four())cout<<4<<endl;
	else if(five())cout<<5<<endl;
	else if(six())cout<<6<<endl;
	else cout<<7<<endl;
}

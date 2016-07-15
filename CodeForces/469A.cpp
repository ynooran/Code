#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

bool cando[110];

int main()
{
	int n,a,b;
	cin>>n;
	cin>>a;
	FOR(i,0,a)
	{
		int tmp;
		cin>>tmp;
		cando[tmp] = true;
	}
	cin>>b;
	FOR(i,0,b)
	{
		int tmp;
		cin>>tmp;
		cando[tmp] = true;
	}
	FOR(i,1,n)
		cando[i+1] &= cando[i];
	if(cando[n])
		cout<<"I become the guy."<<endl;
	else
		cout<<"Oh, my keyboard!"<<endl;
}

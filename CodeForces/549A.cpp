#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

char table[51][51];

bool isFace (int i,int j)
{
	string tmp;
	tmp[0] = table[i][j];
	tmp[1] = table[i][j+1];
	tmp[2] = table[i+1][j];
	tmp[3] = table[i+1][j+1];
	//cerr<< (search(tmp,tmp+3,'f') && search(tmp,tmp+3,'a') && search(tmp,tmp+3,'c') && search(tmp,tmp+3,'e'))<<endl;
	cerr<<tmp.search('f') <<endl;
	return 0;
}
int main ()
{
	int n,m,answer=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>table[n][m];
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1;j++)
			if(isFace(i,j))
				answer++;
	cout<<answer<<endl;
}


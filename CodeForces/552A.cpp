#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main ()
{
	int n,answer=0;
	cin>>n;
	while(n--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		answer += (x2-x1+1)*(y2-y1+1);
	}
	cout<<answer<<endl;
}


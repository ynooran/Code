#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int sys[31000];

int main()
{
	int n,t;
	cin>>n>>t;
	for(int i=1; i<n; i++)
		cin>>sys[i];
	int j = 1;
	while(j<t)
		j += sys[j];
	if(j==t)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
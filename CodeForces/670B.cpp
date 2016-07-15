#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 100000;
int n,k,id[MAX+1];
int main()
{
	cin>>n>>k;
	FOR(i,0,n)
		cin>>id[i];
	FOR(i,0,MAX+1)
	{
		if(k>i+1)
		{
			k-=i+1;
			continue;
		}
		FOR(j,0,i+1)
		{
			k--;
			if(!k)
				cout<<id[j]<<endl;
		}
		if(k<=0)
			break;
	}
}

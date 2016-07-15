#include <iostream>
#include <bitset>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
bitset<21> b;
int main()
{
	int n;
	cin>>n;
	b = n;
	for(int i=20; i>=0;i--)
		if(b[i])
			cout<<i+1<<" ";
	cout<<endl;
}


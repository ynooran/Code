#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n ,m;
int main()
{
	cin>>n>>m;
	for(int i = 1; m>=i; i = i%n + 1)
		m-=i;
	cout<<m<<endl;
}

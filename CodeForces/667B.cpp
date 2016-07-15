#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n;
int m,sum;
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		sum+=tmp;
		m = max(m, tmp); 
	}
	cout<<(2*m - sum + 1)<<endl;
}


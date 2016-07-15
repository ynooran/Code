#include <iostream>
#include <queue>
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int MAX = 1e9;
int n,a[3];
bool ans (int x)
{
	for(int i=0; i<=x/a[0]; i++)
		for(int j=0; j<=(x-i*a[0])/a[1]; j++)
			if((x-i*a[0] - j*a[1])%a[2] == 0)
				return true;
	return false;
}
int main()
{
	a[0] = 1234;
	a[1] = 123456;
	a[2] = 1234567;
	cin>>n;
	cout<<(ans(n) ? "YES" : "NO")<<endl;
}

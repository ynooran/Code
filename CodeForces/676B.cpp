#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,t;
int main()
{
	cin>>n>>t;
	int k = -1 + sqrt(1+8*t);
	k/=2;
	if(k>n)
		k=n;
	k = (k*(k+1))/2;
	cout<<n<<endl;
}

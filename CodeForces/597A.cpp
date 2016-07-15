#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	long long a,b,k;
	cin>>k>>a>>b;
	a = a+k-1;
	a-=(a%k + k)%k;
	a/=k;
	b-=(b%k +k)%k;
	b/=k;
	cout<<b-a+1LL<<endl;
}


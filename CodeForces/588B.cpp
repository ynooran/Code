#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long n;
int main()
{
	cin>>n;
	for(long long i=2; i*i<= n; i++)
		while(n%(i*i)==0)
			if(n%i==0)
			n/= i;
	cout<<n<<endl;
}


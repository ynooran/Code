#include <iostream>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;

int main()
{
	long long n,x;
	long long ans =0;
	cin>>n>>x;
	for(long long i=min(x,n); i*i > x ; i--)
		if(!(x%i))
			ans+=2;
	long long l = sqrt(x);
	if((l<=n) && (l*l == x))
		ans++;
	cout<<ans<<endl;
}


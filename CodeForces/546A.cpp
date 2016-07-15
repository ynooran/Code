#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long k, n, w;
int main()
{
	cin>>k>>n>>w;
	w *= (w+1);
	w /= 2;
	w *= k;
	w -= n;
	cout<<(w<0 ? 0 : w)<<endl;
}


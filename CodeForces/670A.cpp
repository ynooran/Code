#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n;
int main()
{
	int low,high;
	cin>>n;
	low = 2*(n/7);
	high = 2*((n+6)/7);
	if(n%7 == 6)
		low++;
	if(n%7 == 1)
		high--;
	cout<<low<<" "<<high<<endl;
}

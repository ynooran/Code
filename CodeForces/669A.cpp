#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int stones;
int main()
{
	cin>>stones;
	cout<<(2*(stones/3) + ((stones%3) ? 1:0) );
}

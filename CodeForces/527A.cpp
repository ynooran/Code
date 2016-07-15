#include <iostream>

using namespace std;

long long int numShips(long long int a,long long int b)
{
	if(!b)
		return 0;
	return (a/b) + numShips(b, a%b);
}

int main()
{
	long long int a,b;
	cin>>a>>b;
	cout<<numShips(a,b);
	return 0;
}
	



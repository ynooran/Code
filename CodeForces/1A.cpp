#include <iostream>
#include <cmath>


using namespace std;

int main()
{
	long long int n,m,a;
	cin>>n>>m>>a;
	n = ceil(n/(double)a) * ceil(m/(double)a);
	cout<<n;
}

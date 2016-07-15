#include <iostream>
using namespace std;
int n,a;
int main()
{
	cin>>n>>a;
	cout<<1+(a%2 ? a-1:n-a)/2<<endl;
}


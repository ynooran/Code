#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int n, a[1000];
int main()
{
	cin>>n;
	FOR(i,0,n)
		cin>>a[i];
	cout<<(*min_element(a,a+n) > 1 ? 1: -1)<<endl;
}

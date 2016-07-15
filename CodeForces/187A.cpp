#include <iostream>
using namespace std;
const int MAX = 2*1e5 + 1;
int n, a[MAX], val[MAX], i;
int main()
{
	cin>>n;
	for(i=1; i<=n; i++)
		cin>>a[i];
	for(i=1; i<=n; i++)
	{
		int tmp;
		cin>>tmp;
		val[tmp] = i;
	}
	for(i=1;val[a[i]]>val[a[i-1]];i++);
	cout<<n-i+1<<endl;
}


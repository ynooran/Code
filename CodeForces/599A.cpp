#include <iostream>
#include<algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	int a[3];
	FOR(i,0,3)
		cin>>a[i];
	sort(a,a+3);
	if(a[2]>a[0] + a[1])
		cout<<2*(a[0] + a[1])<<endl;
	else
		cout<<a[0] + a[1] + a[2] <<endl;
}


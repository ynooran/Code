#include <iostream>
#include<iomanip>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	if(b>a)
		cout<<-1<<endl;
	else if(a==b)
		cout<<a<<endl;
	else
	{
		int k = a/b;
		while(!(k%2)) k--;
		k++;
		double ans = (double)(a+b)/k;
		cout<<setprecision(10)<<ans<<endl;
	}
}


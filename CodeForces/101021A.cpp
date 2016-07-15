#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int low,high,mid;
string tmp;
int main()
{
	low=1,high = 1000001;
	while(high-low>1)
	{
		mid = (high + low)/2;
		cout<<mid<<endl;
		cin>>tmp;
		if(tmp == "<")
			high = mid;
		else
			low = mid;
	}
	cout<<"! "<<low<<endl;
}

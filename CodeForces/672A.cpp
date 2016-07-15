#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,a[1000];
int digit( int b, int a)
{
	vector<int> d;
	while(a)
	{
		d.push_back(a%10);
		a/=10;
	}
	reverse(d.begin(),d.end());
	return d[b-1];
}
int main()
{
	cin>>n;
	int it = 0;
	FOR(i,1,1000)
	{
		int tmp;
		if(i<10)
			tmp=1;
		else if(i<100)
			tmp=2;
		else
			tmp=3;
		a[i] = a[i-1] + tmp;
		cerr<<dbug(a[i])<<endl;
	}
	int num=0;
	while(n>a[num])
		num++;
	n-=a[num-1];
	cerr<<n<<" "<<num<<endl;
	cout<<digit(n,num)<<endl;
}

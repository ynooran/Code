#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int delta = 10243,MAX=1000000;
vector<int> fib;
int main()
{
	int ans=0;
	fib.push_back(2);
	fib.push_back(3);
	while(1)
	{
		int n = fib.size();
		fib.push_back(fib[n-1] + fib[n-2]);
		if(fib[n]>MAX)
			break;
	}
	FOR(i,100000,MAX)
	{
		bool flag = true;
		for(int j=0;fib[j]<=i && j<fib.size() ;j++)
			if(i%fib[j]==0)
			{
				flag = false;
				break;
			}
		if(flag)
			ans++;
	}
	cerr<< ans << endl; 
}

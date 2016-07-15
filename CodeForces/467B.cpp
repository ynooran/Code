#include <iostream>
#include <bitset>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
bitset <20> array[1002];
int n,m,k,ans;
int main()
{
	cin>>n>>m>>k;
	FOR(i,1,m+2)
	{
		int tmp;
		cin>>tmp;
		array[i] = tmp;
	}
	FOR(i,1,m+1)
	{
		array[i] ^=array[m+1];
		if(array[i].count()<=k)
			ans++;
	}
	cout<<ans<<endl;
}


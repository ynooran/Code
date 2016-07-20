#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
#define pb push_back
using namespace std;
int n, ans;
int32_t main(){
	cin>>n;
	int l = 0;
	FOR(i,0,n)
	{
		int x;
		cin>>x;
		switch(x)
		{
			case 0 : ans++; l = 0; break;
			case 3 : 
				 l = l^3;
				 break;
			default :
				 if(l == x)
					ans++, l=0;
				 else
					 l = x;
		}
	}
	cout<<ans<<endl;
}

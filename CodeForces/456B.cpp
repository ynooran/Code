#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
string s, q;
int n;
int pow(int a,int b)
{
	int ret = 1;
	while(b--)
		ret*=a;
	return ret;
}
int ans(int x){
	return (pow(1,x) + pow(2,x) + pow(3,x) + pow(4,x))%5;
}
int main()
{
	cin>>s;
	s = '0' + s;
	q = s.substr(s.size()-2,2);
	n = stoi(q);
	n%=4;
	cout<<ans(n)<<endl;
}

#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
string s;
int n, m, nqs;
long double C (int a, int b)
{
	if(a>b || a<0)
		return 0;
	if(a==b || !a)
		return 1;
	return C(a-1,b-1) + C(a,b-1);
}
int main()
{
	cin>>s;
	for(char c : s)
		if(c=='+')
			n++;
		else
			n--;
	cin>>s;
	for(char c : s)
		if(c=='+')
			m++;
		else if(c=='-')
			m--;
		else
			nqs++;
		int tmp = nqs+n-m;
		if(tmp&1)
			cout<<0<<endl;
		else
		{
			tmp/=2;
			long double surat, makhraj;
			surat = C(tmp,nqs);
			makhraj = pow(2,nqs);
			cout.precision(15);
			cout<<surat/makhraj<<endl;
		}
}

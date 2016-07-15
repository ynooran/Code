#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
bool a[101];
inline void get(bool& b)
{
	char tmp;
	cin>>tmp;
	if(tmp == '.')
		b = 0;
	else
		b=1;
}
int main()
{
	int n;cin>>n;
	FOR(i,0,n)
		get(a[i]);
	FOR(j,0,n)
		for(int i=1;a[j]&&i*4<n;i++)
			if(a[j+i]&&a[j+2*i]&&a[j+3*i]&&a[j+4*i])
				a[100]=1;
	if(a[100])
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}

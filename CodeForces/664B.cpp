#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,cnt,sum,a[100];
bool sgn[100];
char tmp;
int main()
{
	sgn[0] = a[0] = cnt = sum = 1;
	while(tmp!='=')
	{
		cin>>tmp;
		if(tmp=='-')
			sum--,a[cnt]++;
		else if(tmp=='+')
			sgn[cnt]=true,sum++,a[cnt]++;
		else
			cnt--;
		cnt++;
	}
	cin>>n;
	sum-=n;
	FOR(i,0,cnt)
	{
		while(sgn[i] && sum<0 && a[i]<n)
		{
			a[i]++;
			sum++;
		}
		while(!sgn[i] && sum>0 && a[i]<n)
		{
			a[i]++;
			sum--;
		}
	}
	if(!sum)
	{
		cout<<"Possible \n";
		cout<<a[0]<<" ";
		FOR(i,1,cnt)
		{
			if(sgn[i])
				cout<<"+ ";
			else
				cout<<"- ";
			cout<<a[i]<<" ";
		}
		cout<<"= "<<n<<endl;
	}
	else
		cout<<"Impossible"<<endl;
}

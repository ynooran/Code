#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,cnt[3],pos[3];
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		char tmp;
		cin>>tmp;
		switch(tmp)
		{
			case 'R': cnt[0]++;
				  break;
			case 'G': cnt[1]++;
				  break;
			case 'B': cnt[2]++;
		}
	}
	FOR(i,0,3)
	{
		bool a = cnt[(i+2)%3];
		bool b = cnt[(i+1)%3];
		bool c = a ^ b;
		if(!c || (n-cnt[i]>1 && cnt[i]))
			pos[i] = true;
	}
	if(pos[2])
		cout<<"B";
	if(pos[1])
		cout<<"G";
	if(pos[0])
		cout<<"R";
	cout<<endl;
}

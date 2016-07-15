#include<iostream>
#include<algorithm>
#define FOR(i,a,b) for(int i = a; i<b; i++)
using namespace std;
string s,t;
bool equals (int x1, int y1, int x2, int y2)
{
	if((y1-x1)%2)
	{
		FOR(i,x1,y1)
			if(s[i] != t[x2+i-x1])
				return 0;
		return 1;
	}
	int m1 = (x1+y1)/2;
	int m2 = (x2+y2)/2;
	if(equals(x1,m1,x2,m2))
		return equals(m1,y1,m2,y2);
	return (equals(x1,m1,m2,y2) && equals(m1,y1,x2,m2));
}
int main ()
{
	cin>>s>>t;
	if(equals(0,s.size(),0,t.size()))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}//Worst Case Scenario: O(n^1.6)

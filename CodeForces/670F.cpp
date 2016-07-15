#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
string s,q;
int numDigits (int x){
	if(!x)
		return 0;
	return numDigits(x/10) + 1;
}
int main()
{
	cin>>s>>q;
	int n = s.size();
	while((s.size() - n)<numDigits(n))
		n--;
	while(n)
	{
		int tmp = n%10;
		n/=10;
		s.erase(s.begin() + s.find(tmp+'0'));
	}
	FOR(i,0,q.size())
		s.erase(s.begin() + s.find(q[i]));
	sort(s.begin(),s.end(),greater<char>());
	cout<<s<<endl;
}

#include <iostream>
#include <list>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
char tmp;
int n,m,p;
list<char> s;
list<char>::iterator it;
void del()
{
	int os=0,cs=0;
	if(*it == '(')
	{
		do
		{
			if(*it=='(')
				os++;
			else
				cs++;
			it = s.erase(it);
		} while(os>cs);
		if(it==s.end())
			it--;
	}
	else
	{
		do
		{
			if(*it=='(')
				os++;
			else
				cs++;
			it = s.erase(it);
			it--;
		} while(cs>os);
		if(++it==s.end())
			it--;
	}
}
int main()
{
	cin>>n>>m>>p;
	FOR(i,0,n)
	{
		cin>>tmp;
		s.push_back(tmp);
	}
	it=s.begin();
	while(--p)
		it++;
	while(m--)
	{
		cin>>tmp;
		if(tmp == 'R')
			it++;
		else if(tmp == 'L')
			it--;
		else del();
	}
	for (it=s.begin(); it!=s.end(); ++it)
	    cout << *it;
	cout<<endl;
}

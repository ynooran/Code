#include <iostream>
#include <cstring>
using namespace std;
string a;
bool b1,b2,b3,b4;
int main()
{
	cin>>a;
	if(a.size()<5)
		b4=true;
	else
		for(const char c : a)
		{
			if('a'<=c && 'z'>=c)
				b1 = true;
			else if('A'<=c && 'Z'>=c)
				b2 = true;
			else if('0'<=c && '9'>=c)
				b3 = true;
			if(b1 && b2 && b3)
				break;
		}
	if(b1&&b2&&b3&&!b4)
		cout<<"Correct"<<endl;
	else
		cout<<"Too weak"<<endl;
}

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int logdah(long long int x)
{
	if(x<10)
		return 0;
	else return logdah(x/10) + 1;
}

long long int powdah (int x)
{
	if(!x)
		return 1;
	return 10*powdah(x-1);
}

int main ()
{
	long long int n;
	long long int answer=0;
	cin>>n;
	int digits;
	digits = logdah(n)+1;
	for(int i=1;i<digits;i++)
		answer+=9*powdah(i-1)*i;
	long long int remainder = n - powdah(digits-1) + 1;
	answer += digits * remainder;
	cout<<answer<<endl;
}


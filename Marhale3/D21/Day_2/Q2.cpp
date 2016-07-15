#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10091;
int cur;
bool lost[81];
void show() { FOR(j,0,81) cerr<<lost[j]<<" "<<j<<endl;}

void next() {
	do {
		cur++;
		cur%= 81;
	} while(lost[cur]);
}

int main()
{
	FOR(i,0,80)
	{
		FOR(j,0,22) {
			next();
		}
		lost[cur] = true;
		next();
	}
	int end = cur + 1;
	cerr<<dbug(end)<<endl;

	int tmp = ((1 + (53 - end) + 81)%81);

	int start = 1;
	while (end != 53) {
		start = start % 81 + 1;
		end = end % 81 + 1;
	}


	cerr<<dbug(tmp)<<endl;
	cerr<<dbug(start)<<endl;

	int ans = 1;
	FOR(i,0,1390)
	{
		ans*=tmp;
		ans%=delta;
	}
	cout<<ans<<endl;
}

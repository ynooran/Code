#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10459;
int dp[9][1000];
int a[] = {972,  -1, 273, -1, 932, 911,  -1, 233};
int b[] = { -1, 942, 135, -1, 371,  -1, 311,  -1};
int main()
{
	dp[0][777] = 1;
	FOR(k, 0, 8) {
		int a0 = a[k] == -1 ? 100 : a[k];
		int a1 = a[k] == -1 ? 1000 : a[k] + 1;
		FOR(A, a0, a1) {
			int b0 = b[k] == -1 ? 100 : b[k];
			int b1 = b[k] == -1 ? 1000 : b[k] + 1;
			FOR(B, b0, b1) {
				FOR(C, 0, 1000) {
					int &r = dp[k + 1][(C * A + k + 1) % B];
					r += dp[k][C];
					r %= delta;
				}
			}
		}
	}
	cout << dp[8][777] << endl;
}

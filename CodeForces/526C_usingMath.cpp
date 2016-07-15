#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long hb, hr, wb, wr, c, ans =0;
	cin>>c>>hr>>hb>>wr>>wb;
	int LIMIT = sqrt(c) + 2;
	for(long long i=0; i<LIMIT;i++){
		if(i*wr<=c){
			ans =max(ans, i*hr+ (c-wr*i)/wb * hb);}
		if(i*wb<=c){
			ans =max(ans, i*hb+ (c-wb*i)/wr * hr);}
	}
	cout<<ans;
	return 0;
}// Solution using mathematical proof that proves one of the candies is used atmost rad(c) times.

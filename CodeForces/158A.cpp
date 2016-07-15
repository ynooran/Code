# include <iostream>
# include <cmath>
# include <algorithm>

using namespace std;

int main ()
{
	int nums[50],size,k,i;
	cin>>size>>k;
	for(i=0; i<size; i++){
		cin>>nums[i];
		if(nums[i] == 0)
			break;
	}
	while(nums[k-1]==nums[k] && k<size)
		k++;
	cout<<min(i,k)<<endl;
}


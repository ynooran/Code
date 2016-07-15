#include<stdio.h>

#define LIMIT 5000010

int factor[LIMIT],ans[LIMIT];
void build(){
	for(int i=2;i<LIMIT;i++)
		if(!factor[i])
			for(int j=i;j<LIMIT;j+=i)
				       if(!factor[j])
			       			factor[j] = i;
	ans[1] = 0;
	for(int i=2;i<LIMIT;i++){
		factor [i] = factor[i/factor[i]] + 1;
		ans[i] = factor[i] + ans[i-1];
	}
}

int main(){
	build();
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d%d",&a, &b);
        printf("%d \n",ans[a] -ans[b]);
	}
}

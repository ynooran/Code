#include<stdio.h>

struct tree{
	int height,coordinate;
};

#define LIMIT 100010

tree road [LIMIT];

int main(){
	int n,ans=1;
	bool left= true;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&road[i].coordinate,&road[i].height);
	for(int i=1;i<n;i++){
		int lastpoint = road[i-1].coordinate + road[i-1].height;
		if(left || lastpoint < road[i].coordinate)
			ans++;
		if(left || lastpoint >= road[i].coordinate)
			lastpoint= road[i-1].coordinate;
		if(road[i].coordinate - road[i].height > lastpoint)
			left = true;
		else
			left = false;
	}
	printf("%d \n",ans);
}

#include<iostream>
#include<cstdio>
using namespace std;
int n,ref[114][114];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ref[x][y]=true;
	}
	printf("----\n");
	for(int i=0;i<=7;i++){
		for(int j=i+1;j<=7;j++){
			if(!ref[i][j]){
				printf("%d %d\n",i,j);
			}
		}
	}
}
/*
0 1
2 3
4 5
6 7
0 2
1 3
0 3
1 2
4 6
5 7
4 7
5 6
0 4
1 5
2 6
3 7
0 5
1 6
2 7
3 4
0 6
1 7
2 4
3 5
*/

#include<bits/stdc++.h>
using namespace std;
const int N=510,SIZE=1e5+10;

int n,m;
bitset<SIZE>f[N];

int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
    f[0]=1;
    for(int i=1;i<=500;i++)
        for(int k=0;k<=500;k++)
            if(i-k>=0)f[i]|=f[i-k]<<(k*k);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d%d",&n,&m);
        int C=(n*n-n)/2;
        if(m>C){
			puts("0");
			continue;
		}
		if(m==C){
			puts("1");
			continue;
		} 
        int k=2*(C-m)+n;
        cout<<f[n][k]<<endl;
    }
    return 0;
}
/*
4
3 0
3 1
3 3
4 4
*/
/*
8
40 99
41 100
42 782
43 777
44 888
45 1000
46 1212
47 2333
*/ 

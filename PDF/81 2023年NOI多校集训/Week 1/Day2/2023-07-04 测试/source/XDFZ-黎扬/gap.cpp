#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
    putchar(k%10+'0');
}
//我们由边上往里面推,很容易推出排列是由几个单调上升或下降的区间组成,并且区间之间不能相连
//放弃正解,枚举排列O(n!*n)可以得到20分,特殊情况a[i]=1相当于不能连续,但不会做
//将判断有无解放在中间,优化更多一些,时间复杂度O(n!),期望得分25
const int mod=998244353;
int n,a[2005],b[2005],vis[2005],ans,flag;
void dfs(int k,int sum,int f){
    if(k>n){
        // for(int i=1;i<=n;i++){
        //     cout<<b[i]<<" ";
        // }
        // putchar('\n');
        // int now=1,sum=1;
        // while(now<n){
        //     int f=b[now+1]-b[now];
        //     if(abs(f)!=1){
        //         if(a[now]!=1)
        //             return ;
        //         now++;
        //         sum=1;
        //         continue;
        //     }
        //     int last=now;
        //     now++;
        //     sum++;
        //     while(now<n&&b[now+1]-b[now]==f){
        //         now++;
        //         sum++;
        //     }
        //     for(int i=last;i<=now;i++){
        //         if(a[i]!=sum)
        //             return ;
        //     }
        //     now++;
        //     sum=1;
        // }
        // puts(":::::");
        ans++;
        ans%=mod;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
        if(sum==a[k-1]&&(i-b[k-1]==(abs(f)==1?f:1)||i-b[k-1]==(abs(f)==1?f:-1))&&k!=1)
            continue;
        if(sum!=a[k-1]&&i-b[k-1]!=(abs(f)==1?f:1)&&i-b[k-1]!=(abs(f)==1?f:-1)&&k!=1)
            continue;
        b[k]=i;
        vis[i]=1;
        dfs(k+1,sum==a[k-1]?1:sum+1,b[k]-b[k-1]);
        vis[i]=0;
    }
}
int main(){
	freopen("gap.in","r",stdin);
    freopen("gap.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1,now=a[1],last=a[1];i<=n;i++){
        if(i>last){
            last=i+a[i]-1;
            now=a[i];
        }
        if(a[i]!=now){
            printf("0");
            return 0;
        }
    }
    dfs(1,0,0);
    work(ans);
	return 0;
}
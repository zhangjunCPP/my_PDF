#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
不就是点的最大度数吗?
好像有两种情况,一个是点的最大度数,还有一种是三元环 
那么现在就只需要快速找出三元环就行了,暴力 
*/
int t,n,m,d[1000005],ans,cnt,first[1000005],vis[1000005];
struct q1{
	int u,w,nex;
}a[2000005];
void add(int u1,int w1){
	a[++cnt]={u1,w1,first[u1]};
	first[u1]=cnt;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++){
			d[i]=0;
			vis[i]=0;
			first[i]=0;
		}
		cnt=0;
		for(int i=1,x,y;i<=m;i++){
			x=read();
			y=read();
			add(x,y);
			add(y,x);
			d[x]++;
			d[y]++;
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			for(int j=first[i];j;j=a[j].nex){
				vis[a[j].w]=i;
			}
			for(int j=first[i];j;j=a[j].nex){
				for(int k=first[a[j].w];k;k=a[k].nex){
					if(vis[a[k].w]==i){
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,d[i]);
		}
		work(max(ans,flag?3:0));
		putchar('\n');
	}
	return 0;
} 

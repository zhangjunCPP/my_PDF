#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
} bool vos[1005],vis[15];
struct node{ int l,r,c,id; } a[1005];
int n,res,chose[15],out[1005],in[1005];
bool cmp(node x,node y){
	return out[x.id]-in[x.id]>out[y.id]-in[y.id];
}
void dfs(int k){
	if (k>n){
//		for (int i=1;i<=n;i++)
//			cout<<chose[i]<<' '; puts("");
//		Sleep(50);
		int tot=0;
		for (int i=1;i<=n;i++) vos[i]=0;
		for (int i=1;i<=n;i++){
			vos[chose[i]]=1;
			for (int j=a[chose[i]].l;j<=a[chose[i]].r;j++)
				if (!vos[j]) tot+=a[chose[i]].c;
		}
		res=max(res,tot);
		return ;
	} for (int i=1;i<=n;i++)
		if (!vis[i]){
			vis[i]=1;
			chose[k]=i;
			dfs(k+1);
			chose[k]=0;
			vis[i]=0;
		}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read(); bool fl=1;
	for (int i=1;i<=n;i++){
		a[i].l=read(),a[i].r=read(),a[i].c=read();
		a[i].id=i;
		out[i]=a[i].c*(a[i].r-a[i].l);
		for (int j=a[i].l;j<=a[i].r;j++)
			if (j!=i) in[j]+=a[i].c;
		if (a[i].l!=a[i].r) fl=0;
	}
//	if (fl){ printf("0"); return 0; }
//	if (n<=10){ dfs(1); printf("%d",res); return 0; }
	int ct=1;
	do{
		if (ct==n+1) break;
		sort(a+ct,a+n+1,cmp);
		node now=a[ct];
	//	cout<<now.id<<' ';
		vos[now.id]=1;
		for (int i=now.l;i<=now.r;i++)
			if (!vos[i]) res+=now.c,in[i]-=now.c;
		for (int i=ct+1;i<=n;i++)
			for (int j=a[i].l;j<=a[i].r;j++)
				if (j==now.id) out[i]-=a[i].c;
		ct++;
	} while (ct<=n); //puts("");
	printf("%d",res);
	return 0;
}
/*
转化为图论？ No...
暴力吧 

5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/

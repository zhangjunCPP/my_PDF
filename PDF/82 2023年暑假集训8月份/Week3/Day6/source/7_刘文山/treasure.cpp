#include<bits/stdc++.h>
using namespace std;
int n;
int a[27];
int val[1<<25];
int vis[27],anssum,anss[27];
struct czc{
	int val,id;
}zhouji[27]; 
inline bool cmp(czc x,czc y){
	return x.val>y.val;
}
inline bool dfs(int now,int sum,int col){
	if(now==n){
		if(sum==anssum){
			return true;	
		}
		return false;
	}
	if(!vis[now]){
		vis[now]=col;
		if(dfs(now+1,sum+zhouji[now].val,col)) return true;
		vis[now]=0;
		if(dfs(now+1,sum,col)) return true;
		return false; 
	}
	else{
		if(dfs(now+1,sum,col)) return true;
		return false;
	}
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) zhouji[i].val=a[i],zhouji[i].id=i;
	if(n<=15){
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					val[i]+=a[j];
				}
			}
		}
		int U=(1<<n)-1;
		int ans=0x3f3f3f3f,ansi=0,ansj=0,ansk=0;
		for(int i=0;i<(1<<n);i++){
			int s=U^i;
			for(int j=s; j ;j=(j-1)&s){
				int k=s^j;
				int sum=(max({val[i],val[j],val[k]})-min({val[i],val[j],val[k]}));
				if(sum<ans){
					ans=sum;
					ansi=i;
					ansj=j;
					ansk=k;
				}
			}
			int j=0;
			int k=s^j;
			int sum=(max({val[i],val[j],val[k]})-min({val[i],val[j],val[k]}));
			if(sum<ans){
				ans=sum;
				ansi=i;
				ansj=j;
				ansk=k;
			}
		}
		for(int i=0;i<n;i++){
			if((ansi>>i)&1) cout<<"1 ";
			else if((ansj>>i)&1) cout<<"2 ";
			else cout<<"3 "; 
		}
		cout<<endl;
	}
	else{
		for(int i=0;i<n;i++) anssum+=(a[i]);
		if(anssum%3==0){
			sort(zhouji,zhouji+n,cmp);
			anssum/=3;
			bool f=1;
			for(int i=1;i<=3;i++){
				if(!dfs(0,0,i)){
					f=0;
					break;
				}
			}
			if(f){
				for(int i=0;i<n;i++){
					anss[zhouji[i].id]=vis[i];
				}
				for(int i=0;i<n;i++){
					cout<<anss[i]<<" ";
				}
				return 0;
			}
		}
		cout<<"肘鸡"; 
	}
	return 0;
}
/*
考虑先枚举第一个集合。 
那么根据贪心的来说，肯定希望后两个分的均匀一些。
那么问题就变成了两维！ 快乐。
将一个宝箱集合的任意子集分成两个集合，使得两个集合是均匀的。
考虑开始能不能状压处理一下。
好像可以做到 3^n。
即先枚举每个数，再枚举数的子集，然后就没有什么然后了。
加上三个等价部分，就有60分了？
直接枚举有点过于暴力，考虑能不能用转移的形式来看一下。

*/

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
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
开局构造题?
答案下界是p^(k-1)+(k>1)*p^k+(k>2)*p^(k+1)+... 
咱就是说,有没有一种可能,答案的上界也是这个 
就是不断分组,分组得来的? 
k最大是11左右 
这是一个k^3的复杂度? 
*/
int p,k,ans,pn[55],cnt[55];
vector<int> q[55][2005];
void solve(int now,int val){
	if(val==1){
		for(int i=1;i<=cnt[now-1];i++){
			for(auto j:q[now-1][i]){
				work(j);
				putchar(' ');
			}
			putchar('\n');
		}
		return ;
	}
	for(int i=0;i<p;i++){
		for(int j=0;j<p;j++){
			cnt[now]=0;
			for(int h=1;h<=cnt[now-1];h++){
				cnt[now]++;
				q[now][cnt[now]].clear();
				for(int g=j*pn[val-2],num=0;num<p;num++,g=g+pn[val-1]){
					int f=(g/pn[val-1])*pn[val-1],now1=i*pn[val-2];
					if(f){
						while(now1--){
							g++;
							if(g>f+pn[val-1]-1)
								g=f;
						}
					}
					for(int gg=g,num1=0;num1<pn[val-2];gg++,num1++){
						q[now][cnt[now]].emplace_back(q[now-1][h][gg]);
					}
				}
			}
			solve(now+1,val-1);
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	p=read();
	k=read();
	int now=k;
	pn[0]=1;
	for(int i=1;i<=k+k;i++){
		pn[i]=pn[i-1]*p;
	}
	while(now--){
		ans+=pn[k-1+(k-now-1)];
	}
	work(ans);
	putchar('\n');
	now=k;
	while(now--){
		int val=k-now;
		cnt[0]=0;
		for(int i=0;i<pn[k];i+=pn[val]){
			cnt[0]++;
			q[0][cnt[0]].clear();
			for(int j=i;j<i+pn[val];j++){
				q[0][cnt[0]].emplace_back(j);
			}
		}
		solve(1,val);
	}
	return 0;
}

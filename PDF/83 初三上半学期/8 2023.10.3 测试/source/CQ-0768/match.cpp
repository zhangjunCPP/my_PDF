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
构造题,先放放 
从小到大,贪心构造,复杂度O(nm) 70pts
复杂度瓶颈在于排序和找下一个非零
第二个很好优化 记录指针即可 
排序考虑用bitset比较? 
*/
int n,m,vis[1000005];
vector<int> q[1000005];
set<int> h;
bool cmp(vector<int> a,vector<int> b){
	int now=a.size()-1,now1=b.size()-1;
	while(now>=0&&now1>=0){
		if(a[now]<b[now1])
			return 1;
		if(a[now]>b[now1])
			return 0;
		now--;
		now1--;
	} 
	return now<now1;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	n=read();
	m=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			q[i].emplace_back(read());
		}
		sort(q[i].begin(),q[i].end());
	} 
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++){
		h.clear();
		for(int j=q[i].size()-1;j>=0;j--){
			if(vis[q[i][j]]){
				int flag=0;
				for(int k=q[i][j]+1;k<=m;k++){
					if(!vis[k]){
						flag=1;
						vis[k]=1;
						break;
					}
					if(h.find(k)!=h.end())
						vis[k]=0;
				}
				if(!flag){
					work(-1);
					return 0;
				}
				break;
			} 
			vis[q[i][j]]=1;
			h.insert(q[i][j]);
		}
	}
	for(int i=m;i;i--){
		work(vis[i]);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,l[N];
bool flag[N];
struct node{
	int len,id;
	vector<int> num;
	bool operator < (const node &other)const{
		int i,j;
		for(i=len,j=other.len;i&&j;--i,--j) if(num[i]!=other.num[j]) return num[i]<other.num[j];
		if(!i&&!j) return id<other.id;
		return !i;
	}
}cn[N];
void add(int x){
	if(x==m+1){ puts("-1"); exit(0); }
	flag[x]=true;
	if(flag[x+1]) l[x]=l[x+1];
	else l[x]=x+1;
}
int getl(int x){
	if(l[x]==x) return x;
	return l[x]=getl(l[x]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m+1;++i) l[i]=i;
	for(int i=1;i<=n;++i){
		cn[i].id=i,scanf("%d",&cn[i].len),cn[i].num.resize(cn[i].len+1);
		for(int j=1;j<=cn[i].len;++j) scanf("%d",&cn[i].num[j]);
	}
	sort(cn+1,cn+n+1);
	for(int x=1;x<=n;++x){
		int i,j;
		for(i=cn[x].len;i;--i) if(flag[cn[x].num[i]]) break;
		if(!i){
			for(i=cn[x].len;i;--i) add(cn[x].num[i]);
			continue;
		}
		for(j=i+1;j<=cn[x].len;++j)
			if(cn[x].num[j]>cn[x].num[j-1]+1&&getl(cn[x].num[j-1]+1)<cn[x].num[j]){
				add(getl(cn[x].num[j-1]+1));
				break;
			}
		if(j>cn[x].len) add(getl(cn[x].num[cn[x].len]+1));
		for(i=cn[x].len;i>=j;--i) add(cn[x].num[i]);
	}
	for(int i=m;i;--i) printf(flag[i]?"1":"0");
	return 0;
}

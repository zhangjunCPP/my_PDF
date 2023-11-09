#include<bits/stdc++.h>
const int QWQ=5e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} 
int n,m,a[QWQ],tim[QWQ]; bool v[QWQ];
struct node{
	int tim,val;
	operator <(const node &tmp)const{
		return tim<tmp.tim;
	}
};
set<node> q;
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++) a[i]=read();
	for (int k=1;k<=n;k++){
		int res=0; q.clear();
		for (int i=1;i<=n;i++) tim[i]=v[i]=0;
		for (int i=1;i<=m;i++){
			if (v[a[i]]){
				node tmp={tim[a[i]],a[i]};
				set<node>::iterator it=lower_bound(q.begin(),q.end(),tmp);
				q.erase(it); tim[a[i]]=i;
				q.insert({i,(*it).val});
			} else{
				v[a[i]]=1,res++,tim[a[i]]=i;
				q.insert({i,a[i]});
				if (q.size()>k) v[(*q.begin()).val]=0,q.erase(q.begin());
			}
		} printf("%d ",res);
	}
//	for (int i=1;i<=m;i++){
//		int x=read();
//		if (a[tot]!=x) a[++tot]=x;
//	} m=tot;
//	for (int i=1;i<=m;i++) bl[a[i]].psuh_back(i);
//	
	return 0;
}

/*
4 6
2 1 2 2 1 4
*/


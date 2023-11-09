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

/*#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
bool flag[N];
struct node{
	int id;
	vector<int> num;
	bool operator < (const node &other)const{
		for(int i=m-1;~i;--i) if(num[i]!=other.num[i]){
				//cout<<i<<" "<<num[i]<<" "<<other.num[i]<<endl;
				return num[i]<other.num[i];
			}
		return id<other.id;
	}
};
vector<node> cn;
void pt(){
	for(int i=m-1;~i;--i) printf(flag[i]?"1":"0");
	cout<<"\n-------------------\n";
}
int main(){
	freopen("ex_match4.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m),cn.resize(n+1);
	cn[0].num.resize(m),cn[0].id=0;
	for(int j=0;j<m;++j) cn[0].num[j]=0;
	for(int i=1,k;i<=n;++i){
		cn[i].id=i,scanf("%d",&k),cn[i].num.resize(m);
		for(int j=0;j<m;++j) cn[i].num[j]=0;
		for(int j=1,x;j<=k;++j) scanf("%d",&x),cn[i].num[x-1]=1;
	}
	sort(cn.begin(),cn.end());
	for(int x=1;x<=n;++x){
		cout<<cn[x].id<<endl;
		int i,j;
		for(i=m-1;~i;--i) if(cn[x].num[i]&&flag[i]) break;
		if(i<0){
			for(i=m-1;~i;--i) if(cn[x].num[i]) flag[i]=true;
			pt();
			continue;
		}
		for(j=i+1;j<=m;++j) if(!cn[x].num[j]&&!flag[j]) break;
		flag[j]=true;
		for(i=m-1;i>j;--i) if(cn[x].num[i]) flag[i]=true;
		pt();
	}
	for(int i=m-1;~i;--i) printf(flag[i]?"1":"0");
	return 0;
}
*/

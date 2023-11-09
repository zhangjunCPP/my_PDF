#include<bits/stdc++.h>

using namespace std;
struct node{
	int x,id;
}c[222222];
char a[222222][33],b[222222][33];
int f[3333333][26],ed[3333333],s[3333333],anss[222222];
int tot=0,n;
int add(int i){
	int x=0;
	for(int j=1;j<=strlen(a[i]+1);j++){
		int ch=a[i][j]-'a';
		if(!f[x][ch]){
			f[x][ch]=(++tot);
		}
		x=f[x][ch];
	}
	if(!ed[x]){
		ed[x]=i;
	}
	return 0;
}
int add2(int i){
	int x=0;
	s[x]++;
	for(int j=1;j<=strlen(a[i]+1);j++){
		int ch=a[i][j]-'a';
		if(!f[x][ch]){
			f[x][ch]=(++tot);
		}
		x=f[x][ch];
		s[x]++;
	}
	return 0;
}
int xw(int i){
	int x=0;
	for(int j=1;j<=strlen(b[i]+1);j++){
		int ch=b[i][j]-'a';
		x=f[x][ch];
		if(!x) return n;
	}
	if(ed[x]){
		return ed[x];
	}
	return n;
}
int xw2(int i){
	int x=0,ans=0;
	ans+=s[0];
	for(int j=1;j<=strlen(b[i]+1);j++){
		int ch=b[i][j]-'a';
		x=f[x][ch];
		if(!x) return ans;
		ans+=s[x];
	}
	return ans;
}
int cmp(node x,node y){
	return x.x<y.x;
}
int main(){
  freopen("lihua.in","r",stdin);
  freopen("lihua.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]+1;
		add(i);
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>b[i]+1;
		int yu=xw(i);
		c[i].id=i;
		c[i].x=yu;
	}
	sort(c+1,c+q+1,cmp);
	int now=0;
	for(int i=1;i<=q;i++){
		int rt=c[i].x;
		while(now<rt){
			now++;
			add2(now);
		}
		anss[c[i].id]=xw2(c[i].id);
	}
	for(int i=1;i<=q;i++){
		cout<<anss[i]<<endl;
	}
	return 0;
}


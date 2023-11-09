#include<stdio.h>
#include<vector>

const int N=505;
int n,ci,cb;
char s[N];
struct dy{
	int ty,num;
};
std::vector<dy> a,b;
//int dfs(int u){
//	if(u==ci+1){
//		int s=0;
//		for(dy i:b){
//			if(i.ty==2) 
//		}
//		return ;
//	}
//	int s=0;
//	if(a[u].ty==0){
//		b.push_back({1,0});cb++;
//		if(u>1&&a[u-1].ty==1) b[cb].num+=a[u-1].num;
//		if(u<ci&&a[u+1].ty==1) {b[cb].num+=a[u+1].num;s+=dfs(u+2);}
//		else s+=dfs(u+1);
//		b.erase(b.begin()+cb);cb--;
//		
//		b.push_back({0,0});cb++;
//		if(u>1&&a[u-1].ty==0) b[cb].num+=a[u-1].num;
//		if(u<ci&&a[u+1].ty==0) {b[cb].num+=a[u+1].num;s+=dfs(u+2);}
//		else s+=dfs(u+1);
//		b.erase(b.begin()+cb);cb--;
//	}
//	else {
//		b.push_back({a[u].ty,a[u].num});cb++;
//		s+=dfs(u+1);
//		b.erase(b.begin()+cb);cb--;
//	}
//	return s;
//}
int main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	scanf("%d%s",&n,s);int an[1005]={};
	an['?']=0;an['0']=1;an['1']=2;
	bool f=1;int tt=0;
	for(int i=0;s[i];){
		if(s[i]=='?') f=0;
		if(s[i]=='1') tt++; 
		a.push_back({an[s[i]],0});
		if(s[i]=='0') while(s[i]&&s[i]=='0') {a[ci].num++;i++;}
		else if(s[i]=='1') while(s[i]&&s[i]=='1') {a[ci].num++;i++;}
		else i++;
		ci++;
	}
	if(f&&tt==1){
		for(int i=0;i<ci;i++) if(a[i].ty==2){
			printf("%d\n",n-a[i].num+1);
			return 0;
		}
	}
	else puts("I love czc");
	return 0;
}


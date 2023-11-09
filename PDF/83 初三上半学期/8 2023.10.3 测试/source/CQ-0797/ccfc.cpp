#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}/*x*=fl*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 100005
#define INF 1145141919
#define ULL unsigned long long
#define X 31
#define Y 37
int n;
char s[N];
ULL qpa[N];
ULL hsa[N];
ULL ha(int l,int r){
	return hsa[r]-hsa[l-1]*qpa[r-l+1];
}
ULL qpb[N];
ULL hsb[N];
ULL hb(int l,int r){
	return hsb[r]-hsb[l-1]*qpb[r-l+1];
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	qpa[0]=1;
	qpb[0]=1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		qpa[i]=qpa[i-1]*X;
		hsa[i]=hsa[i-1]*X+s[i]-'a';
	}
	for(int i=1;i<=n;i++){
		qpb[i]=qpb[i-1]*Y;
		hsb[i]=hsb[i-1]*Y+s[i]-'a';
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;3*j<n-i+1;j++){
			int ha1=ha(i,i+j-1);
			int ha2=ha(i+j,i+j*2-1);
			int ha3=ha(n-j+1,n);
			int hb1=ha(i,i+j-1);
			int hb2=ha(i+j,i+j*2-1);
			int hb3=ha(n-j+1,n);
			if(ha1==ha2&&ha2==ha3&&hb1==hb2&&hb2==hb3)cnt++;
		}
		printf("%d ",cnt);
	}
	puts("");
	return 0;
}
/*
ouvouvouvouvou
*/

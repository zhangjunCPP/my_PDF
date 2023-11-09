#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){x=0;char c=getchar();/*T fl=1;*/
while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
template<typename T>void write(T x){if(x>=10)write(x/10);putchar((x%10)+'0');}
#define N 100005
#define INF 1145141919
#define LL long long
#define ULL unsigned long long
//#define int LL
char s[N];
char t[N];
int k,q,n,m;
#define X 31
#define Y 37
ULL hs1[N],ht1[N],q1[N];
ULL sa(int l,int r){
//	cout<<l<<","<<r<<"::::";
//	cout<<hs1[r]<<','<<hs1[l-1]<<','<<q1[r-l+1]<<":::\n";
	return hs1[r]-hs1[l-1]*q1[r-l+1];
}
ULL ta(int l,int r){
	return ht1[r]-ht1[l-1]*q1[r-l+1];
}
ULL hs2[N],ht2[N],q2[N];
ULL sb(int l,int r){
	return hs2[r]-hs2[l-1]*q2[r-l+1];
}
ULL tb(int l,int r){
	return ht2[r]-ht2[l-1]*q2[r-l+1];
}
bool check(int ls,int rs,int lt,int rt){
//	cout<<endl<<sa(ls,rs)<<'*'<<ta(lt,rt)<<endl;;
	return sa(ls,rs)==ta(lt,rt)&&sb(ls,rs)==tb(lt,rt);
} 
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(k);
	scanf("%s",s+1);
	read(q);
	n=strlen(s+1);
	q1[0]=q2[0]=1;
	for(int i=1;i<=n;i++){
		q1[i]=q1[i-1]*X;
		q2[i]=q2[i-1]*Y;
		hs1[i]=hs1[i-1]*X+s[i]-'a';
		hs2[i]=hs2[i-1]*Y+s[i]-'a';
//		cout<<hs1[i]<<','<<q1[i]<<' ';
	}
	while(q--){
		scanf("%s",t+1);
		m=strlen(t+1);
		for(int i=1;i<=m;i++){
			ht1[i]=ht1[i-1]*X+t[i]-'a';
			ht2[i]=ht2[i-1]*Y+t[i]-'a';
		}
		int cnt=0;
		for(int i=1;i+m-1<=n;i++){
			int l=i,r=i+m-1;
			int d1=i-1,d2=i+m;
//			/*
			while(l<r){
				int mid=(l+r)>>1;
				if(check(i,mid,1,mid-i+1)){
					d1=Max(d1,mid);
					l=mid+1;
				}else{
					r=mid;
				}
			}
			while(l<r){
				int mid=(l+r+1)>>1;
				if(check(i,mid,1,mid-i+1)){
					d1=Max(d1,mid);
					l=mid;
				}else{
					r=mid-1;
				}
			}
			while(l<r){
				int mid=(l+r)>>1;
				if(check(mid,i+m-1,mid-i+1,m)){
					d2=Min(d2,mid);
					r=mid;
				}else{
					l=mid+1;
				}
			}
			while(l<r){
				int mid=(l+r+1)>>1;
				if(check(mid,i+m-1,mid-i+1,m)){
					d2=Min(d2,mid);
					r=mid-1;
				}else{
					l=mid;
				}
			}
			if(d1<i+m-1&&check(i,d1+1,1,d1+1-i+1))d1++;
			if(d2>i&&check(d2-1,i+m-1,d2-1-i+1,m))d2--; 
			d1++,d2--; 
//			*/
//			cout<<i<<','<<i+m-1<<"::"<<d1<<','<<d2<<endl;
//			cout<<check(2,2,1,1)<<endl;
			if(d1==i+m||Max(d2-d1,d1-d2)<k||m-1<k)cnt++;
		}
		printf("%d\n",cnt);
	}
}
/*
2
baccbcbabc
7
a
abc
aaa
bbb
abbb
acbbc
iamasuperlongstring
*/

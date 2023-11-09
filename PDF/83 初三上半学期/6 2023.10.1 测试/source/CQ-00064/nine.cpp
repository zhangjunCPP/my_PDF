#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
}
int k,x,y;
int S;
signed main(){
	FRE();
	k=read(),x=read(),y=read();
	S=abs(x)+abs(y);
	if(!(k&1)&&(abs(x)+abs(y))&1){
		puts("-1");
		return 0;
	}
	if(x>=0&&y<=0){
		for(int i=1;i<=1e7;++i){
		if((i*k-S)&1)continue;
		int su=(i*k-S)/2;
		int che=2*k-2*S-(abs(y)+su)%k;
		int d=k-abs(x)-(abs(y)+su)%k;
		if(che>=k)continue;
		d+=(k-1-d%k);
		if(d>su)continue;
		int s=su-d;
		printf("%d\n",i);
		int a=0,b=0;int flag=1;
		int dd=d,ss=s+abs(y);
		int aa=d+abs(x),bb=s;
		int aaa=i;
		while(aaa--){
			int sum=k;
			int sss=flag;
			if(flag==1){
				a-=min(dd,k);
				sum-=min(dd,k);
				dd-=min(dd,k);
				if(!dd){
					b-=sum;
					ss-=sum;
					sss=2;
				}
			}
			if(flag==2){
				b-=min(ss,k);
				sum-=min(ss,k);
				ss-=min(ss,k);
				if(!ss){
					a+=sum;
					aa-=sum;
					sss=3;
				}
			}
			if(flag==3){
				a+=min(aa,k);
				sum-=min(aa,k);
				aa-=min(aa,k);
				if(!aa){
					b+=sum;
					aa-=sum;
					sss=4;
				}
			}
			if(flag==4){
				b+=k;
			}
			flag=sss;
			wr(a);putchar(' ');wr(b);putchar('\n');
		}
		return 0;
	}
	}
	if(x<=0&&y<=0){//3
		for(int i=1;i<=1e7;++i){
		if((i*k-S)&1)continue;
		int su=(i*k-S)/2;
		int che=2*k-2*S-(abs(y)+su)%k;
		int d=k-abs(x)-(abs(y)+su)%k;
		if(che>=k)continue;
		d+=(k-1-d%k);
		if(d>su)continue;
		int s=su-d;
		printf("%d\n",i);
		int a=0,b=0;int flag=1;
		int dd=d,ss=s+abs(y);
		int aa=d+abs(x),bb=s;
		int aaa=i;
		while(aaa--){
			int sum=k;
			int sss=flag;
			if(flag==1){
				a+=min(dd,k);
				sum-=min(dd,k);
				dd-=min(dd,k);
				if(!dd){
					b-=sum;
					ss-=sum;
					sss=2;
				}
			}
			if(flag==2){
				b-=min(ss,k);
				sum-=min(ss,k);
				ss-=min(ss,k);
				if(!ss){
					a-=sum;
					aa-=sum;
					sss=3;
				}
			}
			if(flag==3){
				a-=min(aa,k);
				sum-=min(aa,k);
				aa-=min(aa,k);
				if(!aa){
					b+=sum;
					aa-=sum;
					sss=4;
				}
			}
			if(flag==4){
				b+=k;
			}
			flag=sss;
			wr(a);putchar(' ');wr(b);putchar('\n');
		}
		return 0;
	}
	}
	if(x>=0&&y>=0){//1
		for(int i=1;i<=1e7;++i){
		if((i*k-S)&1)continue;
		int su=(i*k-S)/2;
		int che=2*k-2*S-(abs(y)+su)%k;
		int d=k-abs(x)-(abs(y)+su)%k;
		if(che>=k)continue;
		d+=(k-1-d%k);
		if(d>su)continue;
		int s=su-d;
		printf("%d\n",i);
		int a=0,b=0;int flag=1;
		int dd=d,ss=s+abs(y);
		int aa=d+abs(x),bb=s;
		int aaa=i;
		while(aaa--){
			int sum=k;
			int sss=flag;
			if(flag==1){
				a-=min(dd,k);
				sum-=min(dd,k);
				dd-=min(dd,k);
				if(!dd){
					b+=sum;
					ss-=sum;
					sss=2;
				}
			}
			if(flag==2){
				b+=min(ss,k);
				sum-=min(ss,k);
				ss-=min(ss,k);
				if(!ss){
					a+=sum;
					aa-=sum;
					sss=3;
				}
			}
			if(flag==3){
				a+=min(aa,k);
				sum-=min(aa,k);
				aa-=min(aa,k);
				if(!aa){
					b-=sum;
					aa-=sum;
					sss=4;
				}
			}
			if(flag==4){
				b-=k;
			}
			flag=sss;
			wr(a);putchar(' ');wr(b);putchar('\n');
		}
		return 0;
	}
	}
	if(x<=0&&y>=0){//2
		for(int i=1;i<=1e7;++i){
		if((i*k-S)&1)continue;
		int su=(i*k-S)/2;
		int che=2*k-2*S-(abs(y)+su)%k;
		int d=k-abs(x)-(abs(y)+su)%k;
		if(che>=k)continue;
		d+=(k-1-d%k);
		if(d>su)continue;
		int s=su-d;
		printf("%d\n",i);
		int a=0,b=0;int flag=1;
		int dd=d,ss=s+abs(y);
		int aa=d+abs(x),bb=s;
		int aaa=i;
		while(aaa--){
			int sum=k;
			int sss=flag;
			if(flag==1){
				a+=min(dd,k);
				sum-=min(dd,k);
				dd-=min(dd,k);
				if(!dd){
					b+=sum;
					ss-=sum;
					sss=2;
				}
			}
			if(flag==2){
				b+=min(ss,k);
				sum-=min(ss,k);
				ss-=min(ss,k);
				if(!ss){
					a-=sum;
					aa-=sum;
					sss=3;
				}
			}
			if(flag==3){
				a-=min(aa,k);
				sum-=min(aa,k);
				aa-=min(aa,k);
				if(!aa){
					b-=sum;
					aa-=sum;
					sss=4;
				}
			}
			if(flag==4){
				b-=k;
			}
			flag=sss;
			wr(a);putchar(' ');wr(b);putchar('\n');
		}
		return 0;
	}
	}
	
	puts("-1");
}

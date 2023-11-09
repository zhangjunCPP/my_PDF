#include<bits/stdc++.h>
using namespace std;
namespace io{
	template<typename T> T read(){
		T x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()){
			if(ch=='-'){
				f=1;
			}
		}
		for(;ch>='0'&&ch<='9';ch=getchar()){
			x=(x<<1)+(x<<3)+(ch^48);
		}
		return f?-x:x;
	}
	template<typename T> void read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()){
			if(ch=='-'){
				f=1;
			}
		}
		for(;ch>='0'&&ch<='9';ch=getchar()){
			x=(x<<1)+(x<<3)+(ch^48);
		}
		x=f?-x:x;
	}
	template<typename T> void write(T x){
		if(x<0){
			x=-x,putchar('-');
		}
		if(x>9){
			write(x/10);
		}
		putchar(x%10+'0');
	}
}
const int mod=998244353;
const int N=2005;
int n,a[N];
namespace n_8{
	int p[N],ans;
	int len[N];
	void init(){
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
	}
	bool check(){
		if(n==1){
			return (a[n]==1);
		}
		for(int i=1;i<=n;i++){
			int flag1=-1,flag2=-1;
			int s1=1,s2=1;
			if(i!=1){
				flag1=(p[i-1]==p[i]-1);
			}
			if(i!=n){
				flag2=(p[i]==p[i+1]-1);
			}
			if(i!=1){
				for(int j=i-1;j;j--){
					if(flag1){
						if(p[j]==p[j+1]-1){
							s1++;
						}else{
							break;
						}
					}else{
						if(p[j]==p[j+1]+1){
							s1++;
						}else{
							break;
						}
					}
				}
			}
			if(i!=n){
				for(int j=i+1;j<=n;j++){
					if(flag2){
						if(p[j-1]==p[j]-1){
							s2++;
						}else{
							break;
						}
					}else{
						if(p[j-1]==p[j]+1){
							s2++;
						}else{
							break;
						}
					}
				}
			}
			if(flag1==flag2){
				len[i]=s1+s2-1;
			}else{
				len[i]=max(s1,s2);
			}
			
		}
//		puts("p:");
//		for(int i=1;i<=n;i++){
//			printf("%d ",p[i]);
//		}
//		puts("");
//		puts("len:");
//		for(int i=1;i<=n;i++){
//			printf("%d ",len[i]);
//		}
//		puts("");
		for(int i=1;i<=n;i++){
			if(a[i]!=len[i]){
				return 0;
			}
		}
		return 1;
	}
//	int cnt=0;
	void work(){
		do{
			ans=(ans+(check()==1))%mod;
//			if(check()){
//				for(int i=1;i<=n;i++){
//					printf("%d ",p[i]);
//				}
//				puts("");
//			}
//			cnt++;
		}while(next_permutation(p+1,p+n+1));
//		printf("%d %d\n",cnt,8*7*6*5*4*3*2*1);
	}
}

/*
p 5 4 3 2 1
a 1 1 1 1 1
5*3*1*2*2
*/
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	io::read(n);
	
	for(int i=1;i<=n;i++){
		io::read(a[i]);
	}
	//n<=8,20pts
	n_8::init();
	n_8::work();
	io::write(n_8::ans);
	
	return 0;
}

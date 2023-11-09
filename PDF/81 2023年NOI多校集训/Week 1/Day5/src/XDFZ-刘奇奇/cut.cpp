#include<bits/stdc++.h>
using namespace std; 
namespace io{
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
const int N=5e5+5;
int n,a[N];
namespace a_1{
	bool check(){
		for(int i=1;i<=n;i++){
			if(a[i]>1){
				return 0;
			}
		}
		return 1;
	}
	int tot=0,www[N];
	int cn1=0,cn2=0;
	int cnt[2];
	void work(){
		www[++tot]=1;
		cnt[a[1]]++;
		a[n+1]=0x3f3f3f3f;
		for(int i=2;i<=n;i++){
			cnt[a[i]]++;
			if(cnt[0]&&cnt[1]){
				www[++tot]=i+1;
				cn1++;
				cnt[0]=cnt[1]=0;
			}else if(!a[i]&&!a[i+1]){
				www[++tot]=i+1;
				cn2++;
			}
		}
		cnt[0]=cnt[1]=0;
		for(int i=www[tot];i<=n;i++){
			cnt[a[i]]++;
		}
		if(!cnt[0]){
			tot--;
		}
	}
}
signed main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	io::read(n);
	for(int i=1;i<=n;i++){
		io::read(a[i]);
	}
//	if(a_1::check()){
		a_1::work();
		printf("%d %d\n",a_1::cn1*2+a_1::cn2,a_1::tot);
		for(int i=1;i<=a_1::tot;i++){
			printf("%d ",a_1::www[i]);
		}
		/*
		6
		1 0 1 1 0 1
		8
		1 0 1 0 1 0 1 0
		*/
//	}
	return 0;
}

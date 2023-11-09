#include <cstdio>
using ll=unsigned long long;
constexpr int N=100010,P1=131,P2=29;
int s[N],*ed=s+1,i=1,j,n,ans[N];
ll Hash1[N],Hash2[N],p1[N],p2[N],H1,H2;
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	p1[1]=P1;
	p2[1]=P2;
	while((*ed=getchar())<97);
	Hash1[i]=Hash2[i]=*ed^=96;
	while((*++ed=getchar())>96){
		i++;
		Hash1[i]=Hash1[i-1]+(*ed^=96)*(p1[i]=p1[i-1]*P1);
		Hash2[i]=Hash2[i-1]+*ed*(p2[i]=p2[i-1]*P2);
	}
	*ed=0;
	n=ed-s-1;
//	printf("%d\n",n);
	for(i=1;i*3<n;i++){
		H1=Hash1[n]-Hash1[n-i];
		H2=Hash2[n]-Hash2[n-i];
		for(j=0;j+i*3<n;j++){
			if(H1==(Hash1[j+i]-Hash1[j])*p1[n-i-j]&&H2==(Hash2[j+(i<<1)]-Hash2[j+i])*p2[n-(i<<1)-j]&&H2==(Hash2[j+i]-Hash2[j])*p2[n-i-j]&&H1==(Hash1[j+(i<<1)]-Hash1[j+i])*p1[n-(i<<1)-j]){
				ans[j]++;
//				printf("%d %d\n",i,j);
			}
		}
	}
	for(i=0;i<n;i++){
		w(ans[i]);
		if(i<n-1)putchar(32);
	}
	putchar(10);
	return 0;
}
// ouvouvouvouvou

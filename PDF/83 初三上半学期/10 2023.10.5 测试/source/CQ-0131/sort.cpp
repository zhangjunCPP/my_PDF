#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=7e5+10;
int n,st[N],al[N],ag[N],cmpcnt;
void my_sort(int a[],int len){
	if(len<=1)return;
	int pivot=a[(int)ceil((len+1)/2)],tot1=0,tot2=0;
	cmpcnt+=len;
	for(int i=1;i<=len;++i){
		if(a[i]<pivot)al[++tot1]=a[i];
		if(a[i]>pivot)ag[++tot2]=a[i];
	}
	my_sort(al,tot1),my_sort(ag,tot2);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)st[i]=read();
	my_sort(st,n);
	printf("%d\n",cmpcnt);
	return 0;
}
/*
5
4 3 5 1 2
*/

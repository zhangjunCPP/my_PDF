#include<stdio.h>
#include<string.h>
#define ull unsigned long long 
const int N=1e5+5;
int n;
char s[N];
ull po[N],m1=13,ha[N];
ull hash(int l,int r){
	return ha[r]-ha[l-1]*po[r-l+1];
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);
	po[0]=1;
	for(int i=1;i<=n;i++) po[i]=po[i-1]*m1;
	for(int i=1;i<=n;i++) ha[i]=ha[i-1]*m1+s[i]-'a';
	for(int i=1;i<=n;i++)
	{
		int l=0,t=0;
		for(int len=1;len*2+i-1<n-len;len++)
		{
//			if(i==3&&len==3) printf("::%llu %llu\n",hash(i,i+len-1),hash(i+len,i+len*2-1));
			if(hash(i,i+len-1)==hash(i+len,i+len*2-1)&&hash(i+len,i+len*2-1)==hash(n-len+1,n)) {
				l=len;
				t++;
//				break;
			}
		}
//		printf("\n:%d %d\n",l,i);
//		if(!l) {printf("0 ");continue;}
//		int t=i;l*=2;
//		while(t+l-1<n-l+1&&hash(i,i+l-1)==hash(t,t+l-1)) t+=l;
//		printf("\n:%d\n",t);
//		t=(t-i)/l;
		printf("%d ",t);
		
	}
	return 0;
}


#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=100007;
const ll M1=1e9+7;
const ll M2=1e9+9;
char str[N];
int n,ptf[N];
ll h1[N],h2[N],r31[N],r37[N];
ll geth1(int l,int r){
	return (h1[r]-h1[l-1]*r31[r-l+1]%M1+M1)%M1;
}
ll geth2(int l,int r){
	return (h2[r]-h2[l-1]*r37[r-l+1]%M2+M2)%M2;
}
bool ifequal(int l1,int r1,int l2,int r2){
	return (geth1(l1,r1)==geth1(l2,r2)&&geth2(l1,r1)==geth2(l2,r2));
}
signed main(){
//	freopen("D:\\down\\ccfc\\ex_ccfc3.in","r",stdin);
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",str+1);
	n=strlen(str+1);
//	for(int i=1;i<=n;i++){
//		printf("%c",str[i]);
//	}
	r31[0]=r37[0]=1;
	for(int i=1;i<=n;i++){
		h1[i]=h1[i-1]*31+(str[i]-'a'+1);
		h1[i]%=M1;
		h2[i]=h2[i-1]*37+(str[i]-'a'+1);
		h2[i]%=M2;
		r31[i]=(r31[i-1]*31)%M1;
		r37[i]=(r37[i-1]*37)%M2;
	}
	if(n>=10000){
		int lim=n-5000;
		for(int i=lim;i<n;i++){
			int sum=0;
			for(int len=1;(n-i)-len*3>0;len++){
	//			int lenB=n-i-len*3;
				if(ifequal(i+1,i+len,i+len+1,i+(len<<1))&&ifequal(i+1,i+len,n-len+1,n)){
					sum++;
				}
			}
			ptf[i]=sum;
		}
		int lst=0,rpt=0,sum0=0;
		for(int i=n-1;i>=lim;i--){
			if(ptf[i]==1){
				if(lst!=0){
					sum0=i-lst-1;
					lst=i;
					rpt=1;
					for(int j=i-1;j>=0;j--){
						if(j-lst-1==sum0){
							ptf[j]=ptf[lst];
							rpt++;
							if(rpt==3){
								ptf[j]++;
								rpt=0;
							}
							lst=j;
						}else{
							ptf[j]=0;
						}
					}
					break;
				}else{
					lst=i;
				}
			}
		}
		for(int i=0;i<n;i++){
			printf("%d ",ptf[i]);
		}
		return 0;
	}
//	printf("\n");
	for(int i=0;i<n;i++){
		int sum=0;
		for(int len=1;(n-i)-len*3>0;len++){
//			int lenB=n-i-len*3;
			if(ifequal(i+1,i+len,i+len+1,i+(len<<1))&&ifequal(i+1,i+len,n-len+1,n)){
				sum++;
			}
		}
		printf("%d ",sum);
//		if(sum!=ptf[i]){
//			printf("Help!\n");
//		}
	}
} 

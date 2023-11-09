#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
char a[N];
int st[N],pos[N];
int ck(int n){
	int top=0;
	for(int i=1;i<=n;i++)if(a[i]=='(')st[++top]=i;
	else{
		if(!top)return 0;
		pos[i]=st[top],pos[pos[i]]=i;
		top--;
	}
	return 1;
}
int main(){
	freopen("ex_bracket3.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	scanf("%s",a+1);
	int n=strlen(a+1);
	if(!ck(n)){
		printf("-1\n");return 0;
	}
	int ans=n;
	cout<<n<<"\n";
	int L=0,R=0,c=0;
	for(int i=1;i<=n&&pos[i]==n-i+1;i++)c++;
	ans=min(ans,n-c*2);
	for(int i=1;i<=n&&a[i]=='(';i++)L++;
	for(int i=n;i&&a[i]==')';i--)R++;
	if(L&&pos[1]==L*2)ans=min(ans,n-L*2);
	if(R&&pos[n]==n-R*2+1)ans=min(ans,n-R*2);
	int l=0,r=0;
	for(int i=c+1;i<=n&&a[i]=='(';i++)l++;
	for(int i=n-c;i&&a[i]==')';i--)r++;
	if(l&&pos[c+1]==c+l*2)ans=min(ans,n-2*(c+l));
	if(r&&pos[n-c]==n-c-2*r+1)ans=min(ans,n-2*(c+r));
	printf("%d",ans);
	return 0;
}

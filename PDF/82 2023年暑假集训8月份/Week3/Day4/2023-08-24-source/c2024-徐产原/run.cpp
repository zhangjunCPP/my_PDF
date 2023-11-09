#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
void Freopen(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}
int p;
long long S;
int main(){
	Freopen();
	scanf("%d%lld",&p,&s);
	if(p%2!=0)return puts("Impossible"),0;
	int a=p/2/2,b=p/2-a,d=a,e;
	long long c=1ll*a*b-s;
	if(1ll*(a-1)*(b-1)<c)return puts("Impossible"),0;
	while(c>=(b-1)){
		c-=(b-1);
		--d;
	}
	e=b-c;
	if(a==d&&b==e){
		for(int i=1;i<=a;i++)printf("2");
		printf("3");
		for(int i=2;i<=b;i++)printf("2");
		printf("3");
		for(int i=a-1;i>=1;i--)printf("2");
		printf("3");
		for(int i=b-1;i>=1;i--)printf("2");
	}
	else if(a==d&&b!=e){
		for(int i=1;i<=a;i++)printf("2");
		printf("3");
		for(int i=2;i<=e;i++)printf("2");
		printf("31");
		for(int i=e+2;i<=b;i++)printf("2");
		printf("3");
		for(int i=a-2;i>=1;i--)printf("2");
		printf("3");
		for(int i=b-1;i>=1;i--)printf("2");
	}
	else if(a!=d&&b==e){
		for(int i=1;i<=a;i++)printf("2");
		printf("33");
		for(int i=a-1;i>d;i--)printf("2");
		printf("1");
		for(int i=3;i<=b;i++)printf("2");
		printf("3");
		for(int i=d-1;i>=1;i--)printf("2");
		printf("3");
		for(int i=b-1;i>=1;i--)printf("2");
	}
	else{
		for(int i=1;i<=a;i++)printf("2");
		printf("33");
		for(int i=a-1;i>d;i--)printf("2");
		printf("1");
		for(int i=3;i<=e;i++)printf("2");
		printf("31");
		for(int i=e+2;i<=b;i++)printf("2");
		printf("3");
		for(int i=d-2;i>=1;i--)printf("2");
		printf("3");
		for(int i=b-1;i>=1;i--)printf("2");
	}
	puts("");
}


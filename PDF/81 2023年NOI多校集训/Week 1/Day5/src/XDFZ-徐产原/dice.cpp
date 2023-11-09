#include<bits/stdc++.h>
using namespace std;
/*
9:00 打完三十分
异或是二进制下的
而m又在变,n这么小，很像搜索啊
感觉成功的方案数很少啊
直接搜
9:03 开始写代码
9:08 放弃了
直接搜必爆
考虑x,y满足怎样的性质时,对于任意z,z^x,z^y必有一个不为m的倍数
不知道...
考虑x,y满足怎样的性质时,一定存在z,使得z^x,z^y都为m的倍数
z^x==m*a
z^y==m*b
z=(m*a)^x=(m*b)^y
(m*a)^(m*b)=x^y
这个(m*a)^(m*b)可以预处理吧...反正x^y最大也就2的17次方
预处理后用vis标记，然后直接枚举异或结果
考虑有没有传递性
(m*a)^(m*b)=x^y
(m*c)^(m*d)=x^z
(m*a)^(m*b)^(m*c)^(m*d)=z^y
好像并没有，但合法情况也少

但还是不知道怎么反着搜啊
输出No得了
9:27 放弃 
*/
int n,m,tp;
int type(){
	if(n==1)return 1;
	else if(m==2)return 2;
	else return 3;
}
void solve1(){
	puts("Yes");
	for(int i=0;i<6;i++)printf("%d ",i*m);
	return;
}
void solve2(){
	puts("Yes");
	for(int i=1;i+(n&1)<=n;i++){
		for(int j=0;j<6;j++)printf("%d ",j*2+1);
		puts("");
	}
	if(n&1){
		for(int j=0;j<6;j++)printf("%d ",j*2);
		puts("");
	}
}
void solve3(){
	puts("No");
}
void Freopen(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&m);tp=type();
	if(tp==1)solve1();
	else if(tp==2)solve2();
	else solve3();
}
#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a-1;i++) cout<<1;
	for(int i=1;i<=b-1;i++) cout<<0;
	return 0;
}
/*
构造题：
考虑全选 1 ，那轻松构造出 a*b-1 个不同子序列。
可以过30。
考虑添入一个 0 ，那么答案可以表示成：
（l+1）(r+1)  其中 l+r=n
(l+1) (r+1)>1e5 应该就能构造了。
ab-1 = (l+1)(r+1)
但是他是 ab-1 不是 ab ，不能直接分解，意味着 ab-1 可能是一个质数，就算分的再平均，也会
GG。
类似的构造，前一半全是 1 ，后一半全是 0 ，好像也会 G
好像不会 G。
设 1 的个数为 l，0 的个数为 r。
那么总个数为：
l*r+l+r = (l+1)(r+1)-1 =a*b -1
所以就这么结束了。 
就这样的 T1 也还是有点水。（鼠都能做） 
*/ 

//�Ͻ�:p^k-1(1+p+p^2+...p^k-1)
//���ǰ�����ֳ�p����.�����ÿһλ�Ҷ���ƥ��ǰ���λ�����������һλ�������ȵľͺ���.
//Ȼ���Ƿ��γ�p����
//���ڿ�����ô�����������:
/*
0 1 2 3 4 ... p-1
0 1 2 3 4 ... p-1
...(p��)
�����в���һ��һ�е����
������(x,(kx+b)%p)(x=0...p-1)����?
��һ��:��kx+b�������Ķ���((x1,kx1+b),(x2,kx2+b)),����������!,����ȷ��һ��һ�κ���!
���������ô��:(x,(kx+b)%p^k)(x=0...p-1)
Ҳ����!(x1-x2)%p!=0 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int p,k,n=1;
	cin>>p>>k;
	for(int i=1;i<=k;i++)n*=p;
	cout<<n*(n-1)/p/(p-1)<<endl;
	for(int i=0,low=1;i<k;i++,low*=p)
	for(int sm=0,high=n/low/p;sm<low;sm++)
	for(int k=0;k<high;k++)
	for(int b=0;b<high;b++,puts(""))
	for(int x=0;x<p;x++)printf("%d ",sm+low*x+low*p*((k*x+b)%high));
	return 0;
}

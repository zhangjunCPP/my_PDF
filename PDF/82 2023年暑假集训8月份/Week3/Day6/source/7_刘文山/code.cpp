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
�����⣺
����ȫѡ 1 �������ɹ���� a*b-1 ����ͬ�����С�
���Թ�30��
��������һ�� 0 ����ô�𰸿��Ա�ʾ�ɣ�
��l+1��(r+1)  ���� l+r=n
(l+1) (r+1)>1e5 Ӧ�þ��ܹ����ˡ�
ab-1 = (l+1)(r+1)
�������� ab-1 ���� ab ������ֱ�ӷֽ⣬��ζ�� ab-1 ������һ������������ֵ���ƽ����Ҳ��
GG��
���ƵĹ��죬ǰһ��ȫ�� 1 ����һ��ȫ�� 0 ������Ҳ�� G
���񲻻� G��
�� 1 �ĸ���Ϊ l��0 �ĸ���Ϊ r��
��ô�ܸ���Ϊ��
l*r+l+r = (l+1)(r+1)-1 =a*b -1
���Ծ���ô�����ˡ� 
�������� T1 Ҳ�����е�ˮ������������ 
*/ 

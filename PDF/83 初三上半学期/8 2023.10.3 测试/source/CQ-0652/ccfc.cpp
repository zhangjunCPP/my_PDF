/*
C ccfc
�ǣ������⣬�����
û��˵����ͷ���ĵ���ֺ
���������һ�±�����ô��ͺ���
�϶�ѡ��40pts�ı��������Ǳ���ö�� $i$��Ȼ����ö�� $A$��Ȼ�����ж� $A$ �Ϳ�����
*/
#include<bits/stdc++.h>
using namespace std;
char s[114514];
int ans[114514];
int main()
{
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=n;i;i--)
	{
		for(int j=n;j>n-(n-i)/3;j--)
		{
			int len=n-j+1;
			bool ad=true;
			for(int k=1;k<=2*len;k++)if(s[i+k-1]!=s[j+(k-1)%len])ad=false;
			ans[i]+=ad;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}

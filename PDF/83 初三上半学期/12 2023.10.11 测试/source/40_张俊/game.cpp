/*
������ϻ��б�ɾ����Ȼ������ͨ����ô�϶�ɾ������
Ҳ����˵��һ�������ʱ��һ����һ��������ʽ
ȥ���˸����������˵�˼·��
����һ�������ʱ��ͼһ����������ʽ����������һ���˾�һ����Ѷ���ı�ɾ�� 
��ˣ�˫�����Թ涨һ�����������˶��Ѷ���ı�ɾ������˭��ɾ�ꡣ
����������ǣ����һ������ǰɾ�����ϵĵ㣬����ʲôӰ�죿

���� 
*/ 

#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	string s;
	cin>>s;
	int len=s.size();
	for(int i=1;i<=m;i++) {
		int tmp;
		cin>>tmp>>tmp;
	}
	int last=m-(n-1);
	char ans;
	bool flag=false;
	while(true){
		for(int i=0;i<len;i++) {
			m--;
			if(m<0) {
				ans=s[i];
				flag=true;
				break;
			}
		}
		if(flag) break;
	}
	if(ans=='P') puts("G");
	else puts("P");
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve(); 

	return 0;
}

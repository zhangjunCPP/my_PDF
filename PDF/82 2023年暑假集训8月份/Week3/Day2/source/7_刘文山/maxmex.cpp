#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,q;
int a[maxn];
int cnt[maxn];
set< pair<int,int> > st;
inline void INSERT(int i){
	bool flag=0;
	auto it=st.lower_bound({a[i],0});
	if(it!=st.end()){
		pair<int,int> now=(*it);
		if(now.first==a[i]+1){
			now.first--;
			st.erase(it);
			st.insert(now);
			flag=1;
		}
	}
	it=st.lower_bound({a[i],0});
	if(it!=st.begin()){
		it=prev(it);
		pair<int,int> now=(*it); 
		if(now.second+1==a[i]){
			if(!flag){
				now.second++;
				st.erase(it);
				st.insert(now);
			} 
			else{
				it=st.erase(it);
				now.second=(*it).second;
				st.erase(it);
				st.insert(now);
			}
			flag=1;
		}
	}
	if(!flag){
		st.insert({a[i],a[i]});
	}
}
inline void ERASE(int i){
	auto it=st.upper_bound({a[i],n+1});
	it=prev(it);
	pair<int,int> now=(*it);
	st.erase(it);
	pair<int,int> now2={now.first,a[i]-1};
	pair<int,int> now3={a[i]+1,now.second};
	if(now2.first<=now2.second) st.insert(now2);
	if(now3.first<=now3.second) st.insert(now3);
}
inline void print(){
	cout<<"czc:"<<endl;
	for(auto v:st){
		cout<<v.first<<" "<<v.second<<endl;
	}
	cout<<endl;
}
inline void solve1(){
	while(q--){
		int k;
		int ans=0;
		scanf("%d",&k);
		memset(cnt,0,sizeof cnt);
		st.clear();
		for(int i=1;i<=k;i++){
			cnt[a[i]]++;
			if(cnt[a[i]]==1){
				INSERT(i);		
			}
		}
		if((*st.begin()).first==0) ans=((*st.begin()).second+1);
		for(int r=k+1,l=1;r<=n;l++,r++){
			if(a[r]==a[l]) continue;
			cnt[a[r]]++;
			if(cnt[a[r]]==1) INSERT(r);
			cnt[a[l]]--;
			if(!cnt[a[l]]) ERASE(l);
			if((*st.begin()).first==0) ans=max(ans,(*st.begin()).second+1);
		}
		printf("%d\n",ans);
	}
}
int R[maxn][11],ANS[11];
inline void solve2(){
	memset(ANS,0x3f,sizeof ANS);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=10;j++){
			if(a[i]==j) R[i][j]=i;
			else R[i][j]=n+1;
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=0;j<=10;j++){
			R[i][j]=min(R[i+1][j],R[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		int len=0;
		for(int j=0;j<=10;j++){
			if(R[i][j]>n) break;
			len=max(len,R[i][j]-i+1);
			ANS[j]=min(ANS[j],len);
		}
	}
	while(q--){
		int k;
		scanf("%d",&k);
		int ans=-1;
		while(ans<10 && ANS[ans+1]<=k) ans++;
		printf("%d\n",ans+1); 
	}
}
int main(){
//	freopen("czc.txt","r",stdin);
//	freopen("czc.out","w",stdout);
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout); 
//	int x=clock();
	scanf("%d",&n);
	bool f=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>10) f=0;
	}
	scanf("%d",&q);
	if(f) solve2();
	else solve1();
//	cout<<clock()-x<<endl;
	return 0;
}
/*
ǰ 50 ����������ÿ��ѯ������ø����ݽṹ����ά��һ�£���ֿ�+bitset��
Ҳ�����ر��ά���� 
20 ����ÿ���𰸵��������䡣 
ֱ�ӿ����⡣
Ӧ�ú� Subtask 3�й�ϵ��Ҳû�ж���ϵ��
mex ����ܷ���
��Ȼ���е����ԣ���ûʲô�á�
Ӧ�û���һ�����ݽṹ�⡣
Ҳ��һ����ֻ���� 128 MB��
�ʼԤ�����ǲ���һ�����ͼ�����n log n * ���β��� ѽ��
�𾪣���������� n*(n+1)/2 ��û�е���
MM���ģ�����ö��ġ�
���ȱ���Ŀ��ٻش��ѯ���ͼ���Ԥ����
����ö�����䲻��ѧ��
����ÿ���𰸶���һ�������С��
���е����ԣ����Ա����һ���ж����⡣
�ܷ�Ԥ�����ÿ���㵽��ĳ��ֵʱ����С���䡣
�ǿ������Ե��Ƶģ�������� n^2 �ˡ�
���� a_i<=10 ���ơ�
MD �Ҳ����ˡ�
ֵ���ĺ͹�һ����
a_i<=10 ����α�ˡ�//û�� 
Ҳ������ܻ�� n^2 / w ��������
��ʵ�������� qn ���������൱�ڳɹ�һ���ˡ�
���ֱ���� qn^2 �ģ�ƿ������ά��ֵ��
��һ������ά��ֵ��
��ʵҲ�����벢�鼯��
˵ʵ������setͦ��ά���ģ�
���Ӷ� q n long n��
 
*/ 

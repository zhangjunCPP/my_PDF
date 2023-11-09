#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,bool> mp;
void move(int &x,int&y,int f){
	if(f==0)y++;
	if(f==1)x++;
	if(f==2)y--;
	if(f==3)x--;
	mp[{x,y}]=1;
}
int main(){
	freopen("run.out","r",stdin);
//	freopen(".out","w",stdout);
	char s[1212];
	scanf("%s",s);
	int n=strlen(s);
	cout<<n<<endl;
	int x=0,y=0,f=0;
	for(int i=0;i<n;i++){
		if(s[i]=='2')move(x,y,f);
		if(s[i]=='1')f--,f=(f+4)%4,move(x,y,f);
		if(s[i]=='3')f++,f=f%4,move(x,y,f);
		cout<<x<<" "<<y<<endl;
	}
	for(int i=20;i>=-20;i--){
		for(int j=-20;j<=20;j++)cout<<mp[{j,i}];
		cout<<endl;
	}
	return 0;
}


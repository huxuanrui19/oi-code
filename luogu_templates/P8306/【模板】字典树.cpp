#include<bits/stdc++.h>
using namespace std;
typedef short ll;
const int N=3e6+10;
int cnt=0,a[N][63],tot[N];
int judge(char c){
	if(c>='a'&&c<='z') return int(c-'a');
	if(c>='A'&&c<='Z') return int(c-'A'+26);
	return int(c-'0'+52);
}
void build(char *s){
	int now=0;
	for(int i=0;i<strlen(s);i++){
		int id=judge(s[i]);
		if(a[now][id]==0){
			cnt++;
			a[now][id]=cnt;
		}
		now=a[now][id];
		tot[now]++;
	}
}
int ask(char *s){
	int now=0;
	for(int i=0;i<strlen(s);i++){
		int id=judge(s[i]);
		if(a[now][id]==0) return 0;
		now=a[now][id];
	}
	return tot[now];
}
char s1[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
        for(int i=0;i<=cnt;i++){
    		tot[i]=0;
    		for(int j=0;j<63;j++){
    			a[i][j]=0;
    		}
    	}
    	cnt=0;
		for(int i=1;i<=n;i++){
			cin>>s1;
			build(s1);
		}
		for(int i=1;i<=q;i++){
			cin>>s1;
			int tmp=ask(s1);
			cout<<tmp<<endl;
		}
	}
	return 0;
}


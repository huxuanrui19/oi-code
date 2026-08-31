#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[15],c[3][10];
int m[17][3];
void init(){
	for(int i=1;i<=9;i++){
		for(int j=0;j<3;j++) m[i][j]=i;
	}
	for(int i=1;i<=7;i++){
		for(int j=0;j<3;j++) m[i+9][j]=i+j;
	}
}
int ans=0,ta[10],tb[10];
void dfs2(int lb,int lj,int lstb,int a,int b){
	if(lj==lb+1){
		int cnt=0,flag=1,mark=0;
		for(int i=1;i<=9;i++){
			if(ta[i]>4) flag=0;
			int num=min(ta[i],c[a][i]);
			if(c[a][i]-num>=2&&mark!=1) mark=1;
			cnt+=num;
		}
		for(int i=1;i<=9;i++){
			if(tb[i]>4) flag=0;
			int num=min(tb[i],c[b][i]);
			if(c[b][i]-num>=2&&mark!=1) mark=1;
			cnt+=num;
		}
		if(mark==0){
			for(int i=1;i<=9;i++){
				if(ta[i]>4) flag=0;
				int num=min(ta[i],c[a][i]);
				if(c[a][i]-num==1&&c[a][i]<4&&mark!=1) mark=1;
			}
			for(int i=1;i<=9;i++){
				if(tb[i]>4) flag=0;
				int num=min(tb[i],c[b][i]);
				if(c[b][i]-num==1&&c[b][i]<4&&mark!=1) mark=1;
			}
			if(mark==1) cnt++;
		}
		else cnt+=2;
		if(flag==1) ans=max(ans,cnt);
		return;
	}
	for(int i=lstb;i<=16;i++){
		int flag=1;
		for(int j=0;j<3;j++){
			tb[m[i][j]]++;
			if(tb[m[i][j]]>4) flag=0;
		}
		if(flag) dfs2(lb,lj+1,i,a,b);
		for(int j=0;j<3;j++) tb[m[i][j]]--;
	}
}
void dfs1(int la,int li,int lsta,int a,int b){
	if(li==la+1){
		dfs2(4-la,1,1,a,b);
		return;
	}
	for(int i=lsta;i<=16;i++){
		int flag=1;
		for(int j=0;j<3;j++){
			ta[m[i][j]]++;
			if(ta[m[i][j]]>4) flag=0;
		}
		if(flag) dfs1(la,li+1,i,a,b);
		for(int j=0;j<3;j++) ta[m[i][j]]--;
	}
}
int cal(int a,int b){
	for(int la=0;la<=4;la++){
		dfs1(la,1,1,a,b);
	}
	return ans;
}
void solve(){
	ans=0;memset(c,0,sizeof(c));
	for(int i=1;i<=14;i++) cin>>a[i];
	for(int i=1;i<=14;i++){
		c[(a[i]-1)/9][(a[i]%9==0?9:(a[i]%9))]++;
	}
	int maxn=0;
	maxn=max(maxn,cal(0,1));
	maxn=max(maxn,cal(0,2));
	maxn=max(maxn,cal(1,2));
	cout<<14-maxn<<"\n";
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;init();
	while(t--){
		solve();
	}
	return 0;
}
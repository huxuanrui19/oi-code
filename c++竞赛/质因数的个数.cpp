#include<bits/stdc++.h>
using namespace std;
int cnt=0,vis[int(1e7+10)],pri[int(1e7+10)],mem[int(1e7+10)];
void init(){
	vis[1]=1;
	mem[1]=0;
	for(int i=2;i<=1e7;i++){
		if(!vis[i]){
			pri[++cnt]=i;
			mem[i]=1;
			for(int j=2;j*i<=1e7;j++){
				vis[i*j]=1;
				if(mem[j]!=0){
					mem[i*j]=mem[i]+mem[j];
				}
			}
		}
	}
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	init();
	int maxn=-1;
	for(int i=n;i<=m;i++){
		maxn=max(maxn,mem[i]);
	}
	cout<<maxn;
	return 0;
}

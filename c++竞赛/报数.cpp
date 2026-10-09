#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int cnt,vis[N],f[N];
bool check(int n){
	while(n){
		if(n%10==7){
			return false;
		}
		n/=10;
	}
	return true;
}
void init(){
	for(int i=1;i<N;i++){
		if(!vis[i]){
			if(check(i)){
				vis[i]=++cnt;
				f[cnt]=i;
			}
			else{
				for(int j=1;j*i<N;j++){
					vis[i*j]=-1;
				}
			}
		}
	}
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		if(vis[x]==-1){
			cout<<"-1\n";
		}
		else{
			cout<<f[vis[x]+1]<<endl;
		}
	}
	return 0;
} 

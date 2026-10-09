#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int n,m,new_n,new_m,f[N*2][N*2];
bool check(int len){
	for(int i=1;i<=new_m;i++){
		int cnt=0;
		for(int j=1;j<=new_n;j+=2){
			if(f[j][i]>=len) cnt++;
			else cnt=0;
			if(cnt>=len) return 1;
		}
		cnt=0;
		for(int j=2;j<=new_n;j+=2){
			if(f[j][i]>=len) cnt++;
			else cnt=0;
			if(cnt>=len) return 1;
		}
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;
			cin>>ch;
			f[i-j+m][(i+j)/2]=(ch=='0');
		}
	}
	new_n=n+m;
	new_m=(n+m)/2;
	for(int i=1;i<=new_n;i++){
		for(int j=new_m;j>=1;j--){
			if(f[i][j]) f[i][j]=1+f[i][j+1];
		}
	}
	int l=0,r=new_n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans-1;
	return 0;
}


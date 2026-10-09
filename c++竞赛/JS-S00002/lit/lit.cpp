#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int n,m,a[N][N];
bool judge(int x,int y,int k){
	if(x<=k||y<=k||(x+k)>n||(y+k)>m) return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int dis=abs(x-i)+abs(y-j);
			if(dis<=k&&dis%2==k%2){
				if(a[i][j]) return 0;
			}
		}
	}
	return 1;
}
bool check(int x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(judge(i,j,x)) return 1;
		}
	}
	return 0;
}
int main(){
	freopen("lit.in","r",stdin);
	freopen("lit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
	}
	int l=0,r=min(n,m),ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}


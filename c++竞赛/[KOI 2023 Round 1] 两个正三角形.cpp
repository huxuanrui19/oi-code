#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10+10;
int n,ans=1e9,a[N][N],p[N][N],tmp[N][N],b[N][N];
void turn(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			tmp[i][j]=p[n+1-j][i-j+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			p[i][j]=tmp[i][j];
		}
	}
	return;
}
void rev(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			tmp[i][j]=p[i][i-j+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			p[i][j]=tmp[i][j];
		}
	}
	return;
}
void solve(int x,int y){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			p[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=x;i++){
		turn();
	}
	for(int i=1;i<=y;i++){
		rev();
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(b[i][j]!=p[i][j]) cnt++;
		}
	}
	ans=min(ans,cnt);
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>b[i][j];
		}
	}
	for(int i=0;i<=2;i++){
		for(int j=0;j<=1;j++){
			solve(i,j);
		}
	}
	cout<<ans;
	return 0;
}


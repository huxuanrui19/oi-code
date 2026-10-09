#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105+10;
struct point{
	int xi,yi;
}pt[N];
int a[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		pt[i]={x,y};
		a[x][y]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]) continue;
			int cnt=0;
			for(int t=1;t<=k;t++){
				if((abs(pt[t].xi-i)+abs(pt[t].yi-j))<=2){
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}


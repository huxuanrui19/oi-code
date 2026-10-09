#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50+10;
int nx,ny,mx,my,a[N][N],b[N][N];
bool check_pos(int x,int y){
	return (x>0&&x<=mx&&y>0&&y<=my);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>nx>>ny;
	for(int i=1;i<=nx;i++){
		for(int j=1;j<=ny;j++){
			cin>>a[i][j];
		}
	}
	cin>>mx>>my;
	for(int i=1;i<=mx;i++){
		for(int j=1;j<=my;j++){
			cin>>b[i][j];
		}
	}
	int ans=0;
	for(int i=2-nx;i<=mx;i++){
		for(int j=2-ny;j<=my;j++){
			int cnt=0,flag=1;
			for(int k=1;k<=nx;k++){
				for(int l=1;l<=ny;l++){
					int newx=k+i-1,newy=l+j-1;
					if(check_pos(newx,newy)){
						if(a[k][l]!=b[newx][newy]) flag=0;
						else cnt++;
					}
				}
			}
			ans=max(ans,cnt*flag);
		}
	}
	cout<<ans;
	return 0;
}


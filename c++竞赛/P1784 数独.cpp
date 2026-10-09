#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10][10],l[10][10],c[10][10],h[10][10],num[10][10];
int ju(int x,int y){
	return ((x-1)/3)*3+(y-1)/3+1;
}
void out(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}
	exit(0);
}
void dfs(int x,int y){
	if(x==1&&y==10){
		out();
		return;
	}
	if(num[x][y]){
		if(x==9&&y==9) out();
		dfs(x%9+1,y+(x/9));
		return;
	}
	else{
		for(int i=1;i<=9;i++){
			if(l[x][i]==1||c[y][i]==1||h[ju(x,y)][i]==1) continue;
			a[x][y]=i;
			l[x][i]=1;
			c[y][i]=1;
			h[ju(x,y)][i]=1;
			dfs(x%9+1,(x/9)+y);
			a[x][y]=0;
			l[x][i]=0;
			c[y][i]=0;
			h[ju(x,y)][i]=0;
		}
		return;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>num[i][j];
			a[i][j]=num[i][j];
			l[i][num[i][j]]=1;
			c[j][num[i][j]]=1;
			h[ju(i,j)][num[i][j]]=1;
		}
	}
	dfs(1,1);
	return 0;
}


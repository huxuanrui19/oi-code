#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
int n,q,st_max[N][20],st_min[N][20],LOG2[N];
void init(){
	LOG2[0]=-1;
	for(int i=1;i<N;i++){
		LOG2[i]=LOG2[i>>1]+1;
	}
	int p=LOG2[n];
	for(int j=1;j<=p;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st_max[i][j]=max(st_max[i][j-1],st_max[i+(1<<(j-1))][j-1]);
			st_min[i][j]=min(st_min[i][j-1],st_min[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int x,int y){
	int p=LOG2[y-x+1];
	return max(st_max[x][p],st_max[y-(1<<p)+1][p])-min(st_min[x][p],st_min[y-(1<<p)+1][p]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>st_max[i][0];
		st_min[i][0]=st_max[i][0];
	}
	init();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<query(x,y)<<"\n";
	}
	return 0;
}


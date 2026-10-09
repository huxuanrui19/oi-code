#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10;
int n,m,a[N];
int query(int x,int y){
	int ans=0;
	for(int i=x;i<=y;i++) ans=max(ans,a[i]);
	return ans;
}
void ins(int x,int y){
	for(int i=n;i>=x+1;i--) a[i+1]=a[i];
	a[x+1]=y;
	n++;
}
void update(int x,int y) {a[x]=y;}
void del(int x,int y){
	int l=x,r=y+1;
	while(r<=n) {a[l]=a[r];l++;r++;}
	n=l;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			cout<<query(x,y)<<"\n";
		}
		else if(op==2){
			ins(x,y);
		}
		else if(op==3){
			update(x,y);
		}
		else{
			del(x,y);
		}
	}
	return 0;
}


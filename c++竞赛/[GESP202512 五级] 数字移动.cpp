#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=20;
int n,a[N],b[N],c[N];
int st[N][M],LOG2[N];
void build(){
	LOG2[0]=-1;
	for(int i=1;i<N;i++) LOG2[i]=LOG2[i>>1]+1;
	int p=LOG2[n];
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int i=1;i<=p;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
int query(int l,int r){
	int p=LOG2[r-l+1];
	return max(st[l][p],st[r-(1<<p)+1][p]);
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build();
	for(int i=1;i<=n;i++){
		if(b[a[i]]==0) b[a[i]]=i,c[a[i]]=-1;
		else c[a[i]]=i;
	}
	int maxn=0;
	//for(int i=1;i<=n;i++) cout<<b[i]<<" "<<c[i]<<"\n";
	for(int i=1;i<N;i++){
		if(b[i]!=0){
			if(b[i]+1==c[i]) continue;
			else{
				int num=query(b[i],c[i]);
				if(num>i){
					maxn=i;
				}
				else if(num==i){
					maxn=max(maxn,query(b[i]+1,c[i]-1));
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}


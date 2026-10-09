#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+10;
struct wa{
	int id,l,r;
	bool operator < (const wa b) const{return l<b.l;}
}w[N*2];
int n,m,n2,go[N][20],res[N];
void init(){
	int nxt=1;
	for(int i=1;i<=n2;i++){
		while(nxt<=n2&&w[nxt].l<=w[i].r){
			nxt++;
		}
		go[i][0]=nxt-1;
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int s=1;s<=n2;s++){
			go[s][i]=go[go[s][i-1]][i-1];
		}
	}
}
void getans(int x){
	int len=w[x].l+m,cur=x,ans=1;
	for(int i=log2(N);i>=0;i--){
		int pos=go[cur][i];
		if(pos&&w[pos].r<len){
			ans+=1<<i;
			cur=pos;
		}
	}
	res[w[x].id]=ans+1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		w[i].id=i;
		cin>>w[i].l>>w[i].r;
		if(w[i].r<w[i].l) w[i].r+=m;
	}
	sort(w+1,w+n+1);
	n2=n;
	for(int i=1;i<=n;i++){
		n2++;
		w[n2]=w[i];
		w[n2].l=w[i].l+m;
		w[n2].r=w[i].r+m;
	}
	init();
	for(int i=1;i<=n;i++){
		getans(i);
	}
	for(int i=1;i<=n;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}


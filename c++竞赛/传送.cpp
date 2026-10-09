#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,q,h[N],nxt[N],pre[N],prel[N],nxtl[N],mark[N];
stack<int> st;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>h[i];
	st.push(1);
	pre[1]=0;
	prel[1]=1;
	for(int i=2;i<=n;i++){
		while(!st.empty()&&h[st.top()]<=h[i]){
			st.pop();
		}
		pre[i]=st.empty()?0:st.top();
		prel[i]=prel[pre[i]]+1;
		st.push(i);
	}
	while(!st.empty()){
		st.pop();
	}
	st.push(n);
	nxt[n]=n+1;
	nxtl[n]=1;
	for(int i=n-1;i>=1;i--){
		while(!st.empty()&&h[st.top()]<=h[i]){
			st.pop();
		}
		nxt[i]=st.empty()?n+1:st.top();
		nxtl[i]=nxtl[nxt[i]]+1;
		st.push(i);
	}
	//for(int i=1;i<=n;i++) cout<<prel[i]<<" "<<nxtl[i]<<"\n";
	int flag=1;
	for(int i=1;i<=n;i++) if(h[i]!=i) flag=0;
	while(q--){
		int k,i;
		cin>>k>>i;
		if(k==1) cout<<prel[i]+nxtl[i]-1<<"\n";
		else if(flag){
			int maxn=i;
			k--;
			while(k--){
				cin>>i;
				maxn=max(maxn,i);
			}
			cout<<(n-maxn+1)<<"\n";
		}
		else{
			memset(mark,0,sizeof(mark));
			int j=i,all=k;
			mark[j]++;
			while(pre[j]){
				j=pre[j];
				mark[j]++;
			}
			j=i;
			while(nxt[j]<=n){
				j=nxt[j];
				mark[j]++;
			}
			k--;
			while(k--){
				cin>>i;
				j=i;
				mark[j]++;
				while(pre[j]){
					j=pre[j];
					mark[j]++;
				}
				j=i;
				while(nxt[j]<=n){
					j=nxt[j];
					mark[j]++;
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(mark[i]==all) cnt++;
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}


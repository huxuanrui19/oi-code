#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int cnt,vis[N],pri[N];
void init()
{
	vis[1]=1;
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            vis[i]=1;
            pri[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(i*pri[j]>=N){
                break;
            }
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                break;
            }
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	init();
	while(q--){
		int k;
		cin>>k;
		cout<<pri[k]<<'\n'; 
	}
	return 0;
}


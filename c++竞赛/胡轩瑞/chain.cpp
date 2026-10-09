#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=110;
const int N=60;
const ll mod=1e9+7;

struct mx{
	ll xlen,ylen;
	ll m[M+1][M+1];
	void init(ll xl,ll yl){
		xlen=xl;ylen=yl;
		memset(m,0,sizeof(m));
	}
	mx operator * (const mx& b)const{
		mx c;
		c.init(xlen,b.ylen);
		for(int i=1;i<=xlen;i++){
			for(int j=1;j<=b.ylen;j++){
				for(int k=1;k<=ylen;k++){
					c.m[i][j]=(c.m[i][j]+(m[i][k]*b.m[k][j])%mod)%mod;
				}
			}
		}
		return c;
	}
}op[N+1];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	ll m,q;
	cin>>m>>q;
	op[0].init(m,m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j+1||i==j-1) op[0].m[i][j]=j;
			if(i==j) op[0].m[i][j]=j*2;
		}
	}
	/*for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			cout<<op[0].m[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=N;i++){
		op[i]=op[i-1]*op[i-1];
	}
	/*
	for(int k=0;k<=N;k++){
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=m;j++){
	            cout<<op[k].m[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    cout<<endl<<endl<<endl;
	}
	*/
	for(int t=1;t<=q;t++){
		ll n;
		cin>>n;
		mx ans;
		ans.init(1,m);
		ans.m[1][1]=1;
		n--;
		int i=0;
		while(n){
		    if(n&1){
		        ans=ans*op[i];
		    }
		    i++;
		    n>>=1;
		}
		cout<<ans.m[1][1]<<'\n';
	}
	return 0;
}


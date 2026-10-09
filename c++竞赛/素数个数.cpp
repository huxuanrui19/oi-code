#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8+10;
bool flag[N];	//flag=1合数和1，flag=0素数 
void sieve(){
	flag[1]=1;
	for(int i=2;i*i<N;i++){
		if(flag[i]==0){
			for(int j=2;j*i<N;j++){		//int j=i;j<N;j+=i; 
				flag[i*j]=1;			//flag[j]=1;
			}
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,ans=0;sieve();
	cin>>n;
	for(int i=1;i<=n;i++){
		if(flag[i]==0) ans++;
	} 
	cout<<ans;
	return 0;
}


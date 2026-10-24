#include<bits/stdc++.h>
using namespace std;
#define uint unsigned int
uint seed,b[int(2e7+10)],f[int(2e7+10)],ans=0;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
int main(){
	uint n;
	cin>>n>>seed;
	for(int i=1;i<=n;i++){
		b[i]=getnext();
	}
	f[1]=1;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			for(int j=1;i*j<=n;j++){
				b[i*j]+=b[j];
				f[i*j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans^=b[i];
	}
	cout<<ans;
	return 0;
}

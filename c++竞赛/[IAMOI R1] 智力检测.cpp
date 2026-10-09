#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char *p1,*p2,buf[1<<20];
inline char gc(){if(p1==p2)p2=(p1=buf)+fread(buf,1,1<<20,stdin);return p1==p2?' ':*p1++;}
inline long long read(){
	register long long s=0; register char c=gc();
	while(c<'0'||c>'9') c=gc();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=gc();
	return s;
}
ll t,k,x,a[64],tmp[61],q[64],bg=0,ed=0;
int main() {
	//ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	tmp[0]=1;
	for(int i=1;i<=60;i++) tmp[i]=(tmp[i-1]<<1);
	//int cnt=0;
	for(int j=1;j<=t;j++){
		k=read();x=read();bg=ed=0;
		if(tmp[60]<=x||x==0) putchar('0');
		else{
			ll pos=0,len=0;
			for(int i=0;i<=60;i++){
				if(tmp[i]&x) a[i]=1,pos=i,len++;
				else if(len!=0) a[i]=0,q[++ed]=len,len=0;	
			}
			if(len!=0) q[++ed]=len,len=0;
			ll mark=1;
			if(k-1!=pos) mark=0;
			else{
				for(int i=bg+1;i<=ed;i++){
					if((i==ed&&q[i]%2==0)||(i!=ed&&q[i]%2==1)){
						mark=0;break;
					}
				}
			}
			putchar(mark+'0');
		}
	}
	return 0;
}

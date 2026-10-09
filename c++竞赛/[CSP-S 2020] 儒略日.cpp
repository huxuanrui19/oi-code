#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll ju=2299160;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		ll r;
		cin>>r;		//base=4713BC 1 1
		if(r<=ju){
			if(r<=365){
				r++;
				int m=0,sum=0;
				mon[2]++;
				for(int i=1;i<=12;i++){
					sum+=mon[i];
					if(sum>=r){
						m=i;
						break;
					}
				}
				cout<<(r-sum+mon[m])<<" "<<m<<" 4713 BC\n";
				mon[2]--;
			}
			else{
				int y=r/(365*4+1)*4,d=r%(365*4+1),flag=1;
				if(d>=366){
					d-=365;
					y++;
					flag=0;
				}
				if(d>=366){
					d-=365;
					y++;
				}
				if(d>=366) d-=365,y++;
				if(flag==1) d++;
				if(flag) mon[2]++;
				int sum=0,m=0;
				for(int i=1;i<=12;i++){
					sum+=mon[i];
					if(sum>=d){
						m=i;
						break;
					}
				}
				cout<<(d-sum+mon[m])<<" "<<m<<" ";
				if(y<4713) cout<<4713-y<<" BC\n";
				else cout<<y-4712<<"\n";
				if(flag) mon[2]--;
			}
		}
	}
	return 0;
}


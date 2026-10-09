#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
int l,r,L,R,k;
int a[N];
void init(){
	for(int i=l;i<=r;i++){
		for(int j=1;j<i;j++){
			for(int k=0;k<i;k++){
				if(j==k){
					continue;
				}
				int t=1,x=j;
				while(x<N){
					a[x]++;
					t++;
					x*=i;
					if(t%2==1){
						x+=j;
					}
					else{
						x+=k;
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>l>>r>>L>>R>>k;
	init();
	for(int i=L;i<=R;i++){
		if(a[i]==k){
			cout<<i<<endl;
		}
	}
	return 0;
}


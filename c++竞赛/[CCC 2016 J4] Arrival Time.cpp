#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
bool judge(int a,int b){
	if(a<7||(a>=10&&a<15)||(a>=19)) return 0;
	else if((a==7||a==15)&&(!b)) return 0;
	else return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);
	int a,b;
	char c;
	cin>>a>>c>>b;
	if(!(judge(a,b)||judge((a+2)%24,b))) printf("%02d:%02d",(a+2)%24,b);
	else if(judge(a,b)){
		int num=0,flag=-1;
		if(a>=7&&a<=10) num=(10-a-1)*60+(60-b),flag=1;
		else num=(19-a-1)*60+(60-b),flag=0;
		int left=(240-num)/2;
		if(flag==1) a=10;
		else a=19;
		a+=left/60;
		b=left%60;
		printf("%02d:%02d",a,b);
	}
	else if(judge(a+2,b)){
		int num=0,flag=-1;
		if(a<=7) num=(7-a-1)*60+(60-b),flag=1;
		else num=(15-a-1)*60+(60-b),flag=0;
		int left=(120-num)*2;
		if(flag==1) a=7;
		else a=15;
		int up=0;
		if(flag==1) up=180;
		else up=240;
		a+=min(left,up)/60;
		b=min(left,up)%60;
		left-=min(left,up);left/=2;
		if(60-b<=left){
			a++;
			b=(b+left)%60;
		}
		else b+=left;
		printf("%02d:%02d",a,b);
	}
	return 0;
}


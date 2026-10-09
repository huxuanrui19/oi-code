#include<bits/stdc++.h>
using namespace std;
string s[25];
struct node{
	int ind,num;
}bu[256];
string ch[256],al="0123456789ABCDEF";
bool comp(node x,node y){
	if(x.num!=y.num){
		return x.num>y.num;
	}
	else{
		return x.ind<y.ind;
	}
}
vector<int> a[25];
int change(char s1,char s2){
	int cnt=0;
	if(s1>='0'&&s1<='9'){
		cnt+=s1-'0';
	}
	else{
		cnt+=s1-'A'+10;
	}
	cnt*=16;
	if(s2>='0'&&s2<='9'){
		cnt+=s2-'0';
	}
	else{
		cnt+=s2-'A'+10;
	}
	return cnt;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<=255;i++){
		bu[i].ind=i; 
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<s[i].size();j+=2){
			a[i].push_back(change(s[i][j],s[i][j+1]));
			bu[change(s[i][j],s[i][j+1])].num++;
		}
	}
	
	sort(bu,bu+256,comp);
	
	for(int i=0;i<=15;i++){
		ch[bu[i].ind]=al[i];
		cout<<al[bu[i].ind/16]<<al[bu[i].ind%16];
	}
	cout<<endl;
	
	for(int i=16;i<=255;i++){
		int minn=1000,k=0;
		for(int j=0;j<=15;j++){
			if(minn>abs(bu[i].ind-bu[j].ind)){
				minn=abs(bu[i].ind-bu[j].ind);
				k=j;
			}
		}
		ch[bu[i].ind]=ch[bu[k].ind];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			cout<<ch[a[i][j]];
		}
		cout<<endl;
	}
	return 0;
}


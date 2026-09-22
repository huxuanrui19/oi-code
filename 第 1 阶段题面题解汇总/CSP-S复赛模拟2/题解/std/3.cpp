#include<bits/stdc++.h>
using namespace std;
 
const int N=1e5+5;
struct A{int l,r,p,num; };
bool fl[N];
vector<A>v[N],v1,v2;
vector<int>del;
set<int>R,num;
int n,m,cnt;//,col[N];
bool operator <(A i,A j) {
    return i.r<j.r;
}
set<A>t[N];
bool cmpr(A i,A j) { return i.r>j.r; }
bool cmpl(A i,A j) { return i.l>j.l; }
bool CMPL(A i,A j) { return i.l<j.l; }
bool CMPR(A i,A j) { return i.r<j.r; }
map<int,int>mp;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        if(!mp[c]) mp[c]=++cnt;
        v[mp[c]].push_back((A){a,b,mp[c],i-1});
    }
    for(int i=1;i<=cnt;i++) {
        int V=v[i].size();
        //printf("%d %d\n",V,i);
        if(!V) continue;
        sort(v[i].begin(),v[i].end(),cmpr);
        R.clear(); int lst=1e9 + 7;
        for(int j=0;j<V;j++) {
            lst=min(lst-1,v[i][j].r);
            R.insert(lst);
        }
        sort(v[i].begin(),v[i].end(),cmpl);
        for(int j=0;j<V;j++) {
            auto it=R.upper_bound(v[i][j].r);
            if(it==R.begin())  {
                puts("Sorry"); return 0;
            }
            it--;
            v[i][j].r=(*it);
            if(v[i][j].l>v[i][j].r) {
                puts("Sorry"); return 0;
            }
            R.erase(it);
            v1.push_back(v[i][j]);
            v2.push_back(v[i][j]);
        }
    }
    sort(v1.begin(),v1.end(),CMPR);
    sort(v2.begin(),v2.end(),CMPL);
    int ans=0;
    for(int i=0,j=0;i<n;i++) {
        if(!fl[v1[i].num]) {
            ans++;
            for(j;j<n&&v2[j].l<=v1[i].r;j++) {   
                if(t[v2[j].p].empty()) num.insert(v2[j].p);
                t[v2[j].p].insert(v2[j]);
            }
            for(auto k=num.begin();k!=num.end();k++) {
                auto it=t[(*k)].begin();
                fl[it->num]=1;
                t[(*k)].erase(it);
                if(t[(*k)].empty()) del.push_back(*k);
            }
            for(auto k=del.begin();k!=del.end();k++) {
                num.erase(*k);
            }
            del.clear();
        }
    }
    printf("%d\n",ans);
    return 0;
}
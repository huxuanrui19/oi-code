#include<bits/stdc++.h>
using namespace std;
int ans, cnt, tot;
string str;
int main(){
freopen("erase.in","r",stdin);
    freopen("erase.out","w",stdout);
    cin >> str;
    for( int i = 0; i < str.size(); i ++ ){
        if( str[i] == 'A' ) cnt ++;
        if( str[i] == 'B' && cnt ) cnt --, ans ++;
        if( str[i] == 'B' ) tot ++;
    }
    cnt = 0;
    for( int i = str.size() - 1; i >= 0; i -- ){
        if( str[i] == 'C' ) cnt ++;
        if( str[i] == 'B' && cnt ) cnt --, ans ++;
    }

    cout << min( ans, tot );
    return 0;
}

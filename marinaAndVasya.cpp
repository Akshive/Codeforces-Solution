#include <bits/stdc++.h>
using namespace std;

#define _CRT_SECURE_NO_DEPRECATE

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 1000000000
#define PB(a)\
push_back(a)

int n, k;
string s1, s2;
vi diff, same;

string s;

char diff_char(char a, char b){
    for(char x = 'a'; x <= 'z'; x++){
        if(x != a && x != b)return x;
    }
}


void fn1(int m){
    int idx = 0;
    while(m--){
        s[same[idx]] = diff_char(s1[same[idx]], s2[same[idx]]);
        idx++;
    }
}

void fn2(int m){
    int idx = diff.size()-1;
    while(m != idx+1){
        s[diff[idx]] = s2[diff[idx]];
        m--;
        idx -= 2;
    }
    while(idx >= 0){
        //cout<<s1[diff[idx]]<<" "<<s2[diff[idx]]<<endl;
        s[diff[idx]] = diff_char(s1[diff[idx]], s2[diff[idx]]);
        idx--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>k;
    cin>>s1>>s2;
    s = s1;
    REP(i,0,n-1){
        if(s1[i] != s2[i])diff.PB(i);
        else same.PB(i);
    }
    //cout<<same.size()<<" "<<diff.size()<<endl;
    if(k > n || k < (diff.size()+1)/2){
        cout<<-1<<endl;
    }
    else{
        if(k > diff.size()){
            fn1(k - diff.size());
            fn2(diff.size());
        }
        else{
            fn2(k);
        }
        cout<<s<<endl;
    }

    return 0;
}

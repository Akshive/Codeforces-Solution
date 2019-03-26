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

const int Max = 1e5+10;
int n, a[Max], pos[Max];

int fn(){
    int idx = pos[1];
    int len = 1, MaxLen = 1;
    REP(i,2,n){
        if(pos[i] > idx){
            len++; idx = pos[i];
        }
        else{
            idx = pos[i]; len = 1;
        }
        MaxLen = max(MaxLen, len);
    }
    return MaxLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
    REP(i,0,n-1){cin>>a[i]; pos[a[i]] = i;}
    cout<<n-fn()<<endl;
    return 0;
}

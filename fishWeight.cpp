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

const int Max = 1e5+100;
int n, m, k;
stack<int> st_a, st_b;
int p_a = 0;
int a[Max], b[Max];
void init(){
    REP(i,0,n-1)cin>>a[i];
    REP(i,0,m-1)cin>>b[i];

    sort(a, a+n, greater<int>());
    sort(b, b+m, greater<int>());
}

bool solve(){
    REP(i,0,n-1){
        if(a[i] > b[i])return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    cin>>n>>m>>k;
    init();
    if(solve())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

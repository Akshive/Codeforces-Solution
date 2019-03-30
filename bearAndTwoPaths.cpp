#include <bits/stdc++.h>
using namespace std;

#define _CRT_SECURE_NO_DEPRECATE

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define IREP(i, a, b)\
for(int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 1000000000
#define CLR(a) memset(a, 0, sizeof(a))
#define RESET(a) memset(a, -1, sizeof(a))
#define MP(a,b) make_pair((int)a, (int)b)
#define MP2(a,b,c) make_pair((int)a, make_pair((int)b, (int)c))
#define EPS 1e-6
#define char_to_int(c)((int)c-(int)'A')
#define PB(a)\
push_back(a)

int n, k, a, b, c, d;
vi v1, v2;

void solve(){
    v1.PB(a); v1.PB(c);
    REP(i,1,n){
        if(v1.size() == n-2)break;
        if(i == d && v1[v1.size()-1] == c)continue;
        if(i == c && v1[v1.size()-1] == d)continue;
        if(i == b && v1[v1.size()-1] == a)continue;
        if(i == a && v1[v1.size()-1] == b)continue;

        if(i != a && i != b && i != c && i != d)v1.PB(i);
    }
    if(v1[v1.size()-1] == c){
        cout<<-1<<endl; return;
    }
    v1.PB(d);
    if(v1[v1.size()-1] == a){
        cout<<-1<<endl; return;
    }
    v1.PB(b);
    if(v1.size() != n){cout<<-1<<endl; return;}
    v2 = v1;
    v2[0] = v1[1]; v2[1] = v1[0];
    v2[n-2] = v1[n-1]; v2[n-1] = v1[n-2];

    map<ii, bool> mp;
    REP(i,0,n-2){
        mp[MP(v1[i], v1[i+1])] = mp[MP(v1[i+1], v1[i])] = 1;
    }
    int cnt = n-1;
    REP(i,0,n-2){
        if((mp.find(MP(v2[i], v2[i+1])) != mp.end()) || (mp.find(MP(v2[i+1], v2[i])) != mp.end()))continue;
        cnt++;
    }
    if(cnt > k)cout<<-1<<endl;
    else{
        REP(i,0,n-1)cout<<v1[i]<<" "; cout<<endl;
        REP(i,0,n-1)cout<<v2[i]<<" ";
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
    cin>>a>>b>>c>>d;
    solve();
    return 0;
}

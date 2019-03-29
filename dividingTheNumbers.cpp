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

vi odd, even;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int idx = 1;
    while(idx < 6e4+1){
        odd.PB(idx++);
        odd.PB(idx);
        idx += 3;
    }
    idx = 2;
    while(idx < 6e4+1){
        even.PB(idx++);
        even.PB(idx);
        idx += 3;
    }

    int n;
    cin>>n;
    if(n&1){
        int size = (n+1)/2;
        if(size&1)cout<<1<<endl;
        else cout<<0<<endl;
        cout<<size<<" ";
        REP(i,0,size-1)cout<<odd[i]<<" ";
        cout<<endl;
    }
    else{
        int size = (n)/2;
        if(size&1)cout<<1<<endl;
        else cout<<0<<endl;
        cout<<size<<" ";
        REP(i,0,size-1)cout<<even[i]<<" ";
        cout<<endl;
    }
    return 0;
}

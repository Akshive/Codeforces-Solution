#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define IREP(i, a, b) \
for (int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 1000000000
#define char_to_int(c)(int(c)-(int)'0')
#define MP(a, b) \
make_pair(a, b)
#define PB(a) \
push_back(a)
#define PI acos(-1)

const int Max = 1e7;
int odd[Max] = {0}, even[Max] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
/*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
*/
    int n;
    cin>>n;
    int a[n];
    REP(i,0,n-1)cin>>a[i];
    int _xor[n];
    _xor[0] = a[0];
    REP(i,1,n-1)_xor[i] = _xor[i-1]^a[i];
//    REP(i,0,n-1)cout<<_xor[i]<<" "; cout<<endl;

    odd[0] = 1;
    ll ans = 0;
    REP(i,0,n-1){
        if(i%2 == 0){
            ans += even[_xor[i]];
            even[_xor[i]] += 1;
        }
        else{
            ans += odd[_xor[i]];
            odd[_xor[i]] += 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

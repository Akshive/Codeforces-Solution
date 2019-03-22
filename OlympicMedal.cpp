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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t1;
    double t2;
    double r1=0, p1=0, p2=INF;
    cin>>t1;
    REP(i,1,t1){cin>>t2; r1 = max(r1, t2);}
    cin>>t1;
    REP(i,1,t1){cin>>t2; p1 = max(t2, p1);}
    cin>>t1;
    REP(i,1,t1){cin>>t2; p2 = min(t2, p2);}
    double A, B;
    cin>>A>>B;
    cout<<fixed<<setprecision(14);
    double ans = r1/sqrt(1.0 + (A*p2)/(B*p1));
    cout<<ans<<endl;
    return 0;
}

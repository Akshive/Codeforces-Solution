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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int arr[n] = {0};
    REP(i,0,n-1){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    ll sum[n] = {0};
    sum[0] = arr[0];
    REP(i,1,n-1){
        sum[i] += sum[i-1] + arr[i];
    }
    ll tot = 0;
    for(int i = 1; i <= n; i *= 4){
        tot += sum[i-1];
    }
    cout<<tot<<endl;
    return 0;
}

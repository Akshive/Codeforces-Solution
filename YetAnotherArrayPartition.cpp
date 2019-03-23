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

bool cmp1(ii a, ii b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

bool cmp2(ii a, ii b){
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m, k;
    cin>>n>>m>>k;

    ii arr[n];
    REP(i,1,n){
        cin>>arr[i-1].first;
        arr[i-1].second = i;
    }
    sort(arr, arr+n, cmp1);
    /*REP(i,1,n){
        cout<<arr[i-1].first<<" "<<arr[i-1].second<<endl;
    }cout<<endl;*/
    sort(arr, arr+m*k, cmp2);
    ll tot = 0;
    REP(i,1,m*k){
        tot += arr[i-1].first;
        //cout<<arr[i-1].first<<" "<<arr[i-1].second<<endl;
    }//cout<<endl;
    cout<<tot<<endl;
    int j = m-1;
    REP(i,1,k-1){
        cout<<arr[j].second<<" ";
        j += m;
    }cout<<endl;
    return 0;
}

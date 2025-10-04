#include<bits/stdc++.h>

using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(n) n.rbegin(), n.rend()
#define coutyes cout << "YES" << nl;
#define coutno cout << "NO" << nl;

// Types
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<ll> > vvl;
typedef vector<pair<ll,ll> > vpl;
typedef pair<ll,ll> pll;
typedef set<ll> sl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;

ll power(ll a, ll b, ll m) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a) % m; b /= 2; a = (a * a) % m; } return ans; }
ll modInverse(ll a, ll m) { return power(a, m - 2, m); }
ll modAdd(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll modMul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
ll modSub(ll a, ll b, ll m) { return ((a % m) - (b % m) + m) % m; }
ll modDiv(ll a, ll b, ll m) { return (modMul(a, modInverse(b, m), m) + m) % m; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(mll v) { cerr << "{ "; for (auto &p : v) {cerr << "(" << p.first << "," << p.second << ") ";}cerr << "}";}
void _print(stack<ll> s) { cerr << "[ "; while (!s.empty()) { cerr << s.top() << " "; s.pop(); } cerr << "]"; }
void _print(queue<ll> q) { cerr << "[ "; while (!q.empty()) { cerr << q.front() << " "; q.pop(); } cerr << "]"; }
void _print(queue<pair<ll, ll> > q) { cerr << "[ "; while (!q.empty()) { _print(q.front()); cerr << " "; q.pop();} cerr << "]";}
void _print(priority_queue<ll> pq) { cerr << "[ "; while (!pq.empty()) { cerr << pq.top() << " "; pq.pop(); } cerr << "]";}
void _print(priority_queue<pair<ll, ll> > pq) { cerr << "[ "; while (!pq.empty()) { _print(pq.top()); cerr << " "; pq.pop(); } cerr << "]"; }
void _print(priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq) { cerr << "[ "; while (!pq.empty()) { _print(pq.top()); cerr << " "; pq.pop(); } cerr << "]"; }

const int N=1e5+10;

vector<vector<int>> divisors(N + 1);

void compute_divisors() 
{
    for (int i = 2; i <= N; i++) 
    {
        for (int j = i; j <= N; j += i) 
        {
            divisors[j].push_back(i);
        }
        
    }
}

class DSU {
    
public:
    vector<int> rank, parent, size;

    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for (int i=0; i<=n; i++){
            parent[i]=i;
        }
    }

    int findUPar(int node)
    {
        if(parent[node]==node) 
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } 
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

ll fact(ll n)
{
    if(n<=1) return 1;
    ll ret = (fact(n-1)%MOD1 * n) % MOD1;
    return ret;
}

bool isValid(ll i, ll j, ll n, ll m){
    if(i>=0 && i<n && j>=0 && j<m) return true;
    return false;
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int>> divisors(N + 1);

// Prime divisors
void compute_divisors() 
{
    for (int i = 2; i <= N; i++) 
    {
        if(divisors[i].empty())
        {
            for (int j = i; j <= N; j += i) 
            {
                divisors[j].push_back(i);
            }
        }
        
    }
}

class SegTree{
public:
    vector<ll> seg;
    SegTree(int n){
        seg.resize(4*n+1);
    }

    void build(ll ind, ll low, ll high, vll &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }

        ll mid = (low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }

    ll query(ll ind, ll low, ll high, ll l, ll r){
        // No overlap
        if(high<l || low>r) return LLONG_MAX;
        
        // Complete Overlap
        if(low>=l && high<=r) return seg[ind];

        // Partial Overlap
        ll mid = (low+high)/2;
        ll left = query(2*ind+1, low, mid, l, r);
        ll right = query(2*ind+2, mid+1, high, l, r);
        return min(left,right);
    }

    void update(ll ind, ll low, ll high, ll i, ll val){
        if(low==high){
            seg[ind] = val;
            return;
        }

        ll mid = (low+high)/2;
        if(i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);

    }
   
};

set<ll> primes;
vector<bool> isPrime(N + 1, true);

void precompute()
{
    isPrime[0] = isPrime[1] = false; 

    for (int i = 2; i * i <= N; i++){
        if(isPrime[i]){
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= N; i++){
        if(isPrime[i]){
            primes.insert(i);
        }
    }
}

// Rabin Karp Rolling Hash Algo

ll p=31;
vll preprocess(string &s)
{
    int n=s.size();
    ll pow=p;
    vll pha(n,0);
    pha[0]=s[0]-'a'+1;  // pha= prefix hash array
    for (int i=1; i<n; i++)
    {
        pha[i]=(pha[i-1] + ((s[i]-'a'+1)*pow) % MOD) % MOD;
        pow = (pow*31) % MOD;
    }
    return pha;
    
}

ll processQuery(ll l, ll r, vll pref)
{
    ll ans=pref[r];
    if(l>0) ans= (ans-pref[l-1] + MOD) % MOD;
    return ans;
}

vll powArr(ll n)
{
    vll ans(n,0);
    ll pow=1;
    for (int i=0; i<n; i++)
    {
        ans[i]=pow;
        pow = (pow*p) % MOD;
    }
    return ans;
}

string toBinary(ll n)
{
    string s;
    while(n)
    {
        int rem = n % 2;
        s+= rem+'0';
        n/=2;
    }
    reverse(all(s));
    return s;
}

// ------------------------x----------------------------x---------------------------x---------------------------x----------------------------x--------------------------x-----------------------//


void krisp()
{
    ll n;
    cin >> n;
    vll a(n,0);
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while(t--)
    {
        krisp();
    }
    return 0;
}





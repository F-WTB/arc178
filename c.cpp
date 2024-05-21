#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

int N, L, A;

const int M = 200001;
int v[M];
set<int> w;
vector<set<int>> s = {{0}};
bool flag = 1;
void search()
{
    int k = s.size();
    s.push_back(set<int>());
    for (int a : s[k - 1])
        for (int x : w)
        {
            if (a + x < M && v[a + x] < 0)
            {
                v[a + x] = k;
                s[k].insert(a + x);
            }
        }
    if (!s[k].size())
        flag = 0;
}

int main()
{
    fill(v + 1, v + M, -1);
    cin >> N >> L;

    for (int i = 0; i < L - 1; ++i)
        if (ll(i + 1) * (L - 1 - i) < M)
            w.insert((i + 1) * (L - 1 - i));

    for (int i = 0; i < N; ++i)
    {
        cin >> A;
        while (v[A] < 0 && flag)
            search();
        cout << v[A] << '\n';
    }
}

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

int N, M, A;
bool b[200000];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> A;
        if (A == 1 || A == N)
        {
            cout << -1 << '\n';
            return 0;
        }
        --A;
        b[A] = 1;
    }

    vector<int> ans;

    queue<int> q;
    for (int i = 0; i < N; ++i)
    {
        if (b[i])
        {
            if (q.empty())
                q.push(i);
            ans.push_back(i + 1);
        }
        else
        {
            if (q.size())
            {
                ans.push_back(q.front());
                q.pop();
            }
            else
                ans.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << (i < ans.size() - 1 ? '\t' : '\n');
}

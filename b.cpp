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

int T, A, B, C;

mint f(mint a, mint b, mint n)
{
    return (a + b) * n / 2;
}

int main()
{
    cin >> T;
    for (int _ = 0; _ < T; ++_)
    {
        cin >> A >> B >> C;
        if (A < B)
            swap(A, B);
        if (C != A && C != A + 1)
        {
            cout << 0 << '\n';
            continue;
        }
        if (C == A)
        {
            mint dif = mint(10).pow(C) - mint(10).pow(A - 1);
            mint Y_inf = mint(10).pow(B - 1);
            mint Y_sup = (A == B ? mint(10).pow(A) - mint(10).pow(A - 1) : mint(10).pow(B));
            cout << f(dif - Y_inf, dif - (Y_sup - 1), Y_sup - Y_inf) << '\n';
        }
        if (C == A + 1)
        {
            mint Y_inf = mint(10).pow(B - 1);
            mint Y_mid = mint(10).pow(A) - mint(10).pow(A - 1);
            mint Y_sup = mint(10).pow(B);
            if (A > B)
                cout << f(Y_inf, Y_sup - 1, Y_sup - Y_inf) << '\n';
            else
            {
                mint ans = f(Y_inf, Y_mid - 1, Y_mid - Y_inf);
                ans += (Y_sup - Y_mid) * Y_mid;
                cout << ans << '\n';
            }
        }
    }
}

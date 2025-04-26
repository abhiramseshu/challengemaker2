#include <bits/stdc++.h>
using namespace std;
#define fast           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int Limit = 10000;
vector<int> SeivesPrime(Limit + 1);
bool solve(int n)
{
    int tar, wind, temp;
    cin >> tar >> wind;
    temp = tar + wind * -1;
    if (temp >= 0 && temp < n * n && SeivesPrime[temp])
    {
        if (temp / n == tar / n)
            return true;
    }
    return false;
}

int main()
{
    fast;
    for (int i = 0; i <= Limit; i++)
    {
        SeivesPrime[i] = 1;
    }
    SeivesPrime[0] = 0;
    SeivesPrime[1] = 0;
    for (long i = 2; i * i < Limit; i++)
    {
        if (SeivesPrime[i])
            for (long j = i * i; j < Limit; j = j + i)
            {
                SeivesPrime[j] = 0;
            }
    }

    int n;
    cin >> n;
    int q;
    cin >> q;
    while (q--)
    {
        if (solve(n))
            cout << "True\n";
        else
            cout << "False\n";
    }

    return 0;
}

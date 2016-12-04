#include <bits/stdc++.h>

using namespace std;

int solve(int n)
{
    int div = 1;
    int count = 1;
    while (div)
    {
        if (div < n)
        {
            count++;
            div = 10 * div + 1;
        }
        div %= n;
    }
    return count;
}

int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    while (cin >> n)
        cout << solve(n) << endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
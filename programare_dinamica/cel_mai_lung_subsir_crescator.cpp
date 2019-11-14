#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int x[N], lg[N];
int main()
{
    int n;
    cout << "n: "; cin >> n;

    srand(time(NULL));

    for(int i = 1; i <= n; i++) {
        x[i] = rand() % 100;
        cout << x[i] << ' ';
        lg[i] = 1;
    }
    cout << '\n';
    for(int i = n-1; i >= 1; i--)
        for(int j = i+1; j <= n; j++)
            if(x[i] <= x[j] && lg[i] < lg[j] + 1)
                lg[i] = lg[j] + 1;

    int mx = 0;
    for(int i = 1; i <= n; i++)
        if(lg[i] > mx)
            mx = i;

    cout << mx << '\n';
    for(int i = 1; i <= n; i++)
        if(lg[i] == mx) {
            cout << x[i] << ' ';
            mx--;
        }
    return 0;
}

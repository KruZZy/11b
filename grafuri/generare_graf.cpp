#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> M;

int main()
{
    int n;
    cout << "n = "; cin >> n;

    int m = (n * (n-1))/2;
    M.reserve((n * (n-1))/2+1);

    for(int i = 1; i < n; i++)
        for(int j = i+1; j <= n; j++)
            M.push_back({i, j});

    for(long long i = 1; i <= (1 << m); i++) {
        cout << "Graful " << i << ":\n";
        for(int j = 0; j < m; j++)
            if(i & (1 << j))
                cout << "[" << M[j].first << ", " << M[j].second << "]\n";
    }
    return 0;
}

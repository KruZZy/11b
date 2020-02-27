#include <bits/stdc++.h>

using namespace std;

ifstream in("graf.in");

const int N = 100,
          oo = INT_MAX/2;

int P[N], dist[N], cost[N][N], n, m;
bool v[N];

void drum(int x) {
    if(P[x] != 0) drum(P[x]);

    cout << x << ' ';
}

int main()
{
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            cost[i][j] = cost[j][i] = oo;

    int x, y, c;
    while(m--) {
        in >> x >> y >> c;
        cost[x][y] = c;
    }
    int start;
    cout << "start: "; cin >> start;

    v[start] = 1;
    dist[start] = 0;
    P[start] = 0;
    for(int i = 1; i <= n; i++) {
        dist[i] = cost[start][i];
        if(cost[start][i] != oo && cost[start][i] != 0)
            P[i] = start;
    }

    int minim, vf = -1;
    do {
        minim = oo;
        for(int i = 1; i <= n; i++)
        if(!v[i] && dist[i] < minim) {
            minim = dist[i];
            vf = i;
        }

        if(minim < oo) {
            v[vf] = 1;
            for(int i = 1; i <= n; i++)
                if(!v[i] && dist[vf] + cost[vf][i] < dist[i]) {
                    dist[i] = dist[vf] + cost[vf][i];
                    P[i] = vf;
                }
        }
    } while(minim < oo);

    int finish;
    cout << "finish: "; cin >> finish;

    drum(finish);
    return 0;
}

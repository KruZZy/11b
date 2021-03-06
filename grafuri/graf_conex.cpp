#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100;

ifstream in("graf.in");

int N, M;
vector<int> A[NMAX];
bool viz[NMAX*NMAX];

inline void addAdj(int x, int y) {
    A[x].push_back(y);
    A[y].push_back(x);
}

void dfs(int x) {
    viz[x] = 1;

    for(const auto& i: A[x])
        if(!viz[i])
            dfs(i);
}

int main()
{
    in >> N >> M;
    int x, y, add = 0;

    for(int i = 1; i <= M; i++) {
        in >> x >> y;
        addAdj(x, y);
    }

    int lst = -1;

    for(int i = 1; i <= N; i++)
        if(!viz[i]) {
            dfs(i);
            if(lst != -1) {
                addAdj(lst, i);
                add++;

                cout << "[" << lst << ", " << i << "]\n";
            }

            lst = i;
        }

    if(add == 0) cout << "Graful este conex.";
    else cout << "Am adaugat " << add << " muchii.";
    return 0;
}

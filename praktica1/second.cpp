#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 2e5 + 5;

vector<int> vec[MAX];
bool visited[MAX];

int bfs(int start, vector<int>& energy) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int minEnergy = energy[start];

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : vec[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                minEnergy = min(minEnergy, energy[neighbor]);
            }
        }
    }

    return minEnergy;
}

int main() {
    int n;
    cin >> n;

    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int out, in;
        cin >> out >> in;
        out -= 1;
        in -= 1;
        vec[out].push_back(in);
        vec[in].push_back(out);
    }
    long long minEnergy = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            minEnergy += bfs(i, energy);
        }
    }
    cout << minEnergy;
}

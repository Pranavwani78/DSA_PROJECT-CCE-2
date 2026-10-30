#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

void dijkstra(int source, const vector<vector<pair<int, int>>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist != dist[u])
            continue;

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INF &&
                dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nMinimum-cost paths from Router R"
         << source + 1 << ":\n";

    cout << "Router\tMinimum Cost\tPath\n";

    for (int i = 0; i < n; i++)
    {
        cout << "R" << i + 1 << "\t";

        if (dist[i] == INF)
        {
            cout << "Unreachable\tNo path\n";
            continue;
        }

        cout << dist[i] << "\t\t";

        vector<int> path;

        for (int v = i; v != -1; v = parent[v])
            path.push_back(v);

        reverse(path.begin(), path.end());

        for (int j = 0; j < path.size(); j++)
        {
            cout << "R" << path[j] + 1;

            if (j + 1 < path.size())
                cout << " -> ";
        }

        cout << "\n";
    }
}

int main()
{
    int n, m;

    cout << "Enter number of routers and communication links: ";
    cin >> n >> m;

    if (n <= 0 || m < 0)
    {
        cout << "Invalid input.\n";
        return 0;
    }

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter each link as: router1 router2 cost\n";

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 1 || u > n || v < 1 || v > n || w < 0)
        {
            cout << "Invalid link.\n";
            return 0;
        }

        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }

    int source;

    cout << "Enter source router: ";
    cin >> source;

    if (source < 1 || source > n)
    {
        cout << "Invalid source router.\n";
        return 0;
    }

    dijkstra(source - 1, graph);

    return 0;
}
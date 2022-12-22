#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

std::vector<int> adj[1001], r[2];
bool v[2][1001];
//int array[5];

enum class typeNum
{
    dfs = 0,
    bfs = 1
};

void PrintDFS()
{
        for (int j : r[0])
            std::cout << j << ' ';
        std::cout << '\n';
}

void PrintBFS()
{
    for (int j : r[0])
        std::cout << j << ' ';
    std::cout << '\n';
}

void SetAdjVector(int nodeCount, int edgeCount, std::vector<int>* adjVector)
{
    for (int i = 0; i < edgeCount; i++)
    {
        int e1, e2;
        std::cin >> e1 >> e2;
        adjVector[e1].push_back(e2); adjVector[e2].push_back(e1);
    }

    for (int i = 1; i <= nodeCount; i++)
        std::sort(adjVector[i].begin(), adjVector[i].end());
}

void DFS(int V)
{
    std::stack<int> stk;
    stk.push(V);
    r[0].push_back(V);
    while (!stk.empty())
    {
        bool pop = true;
        int nd = stk.top();
        v[0][nd] = true;

        for (int nxt : adj[nd])
            if (!v[nxt])
            {
                v[0][nxt] = true;
                stk.push(nxt);
                pop = false;
                r[0].push_back(nxt);
                break;
            }
        if (pop) stk.pop();
    }
}

void BFS(int V)
{
    std::queue<int> q;
    q.push(V);
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        v[1][nd] = true;
        r[1].push_back(nd);

        for (int nxt : adj[nd])
            if (!v[nxt])
            {
                v[1][nxt] = true;
                q.push(nxt);
            }
    }
}

void Merge(int array[], int low, int mid, int high)
{
    int l = low;
    int r = mid + 1;
    int idx = 0;

    int* temp = new int[high - low + 1];

    while (l < mid + 1 && r < high + 1)
    {
        if (array[low] > array[high])
            temp[idx++] = array[r++];
        else
            temp[idx++] = array[l++];
    }

    for (int i = l; l < mid + 1; l++)
    {
        temp[idx++] = array[i];
    }
    for (int i = r; r < high + 1; r++)
    {
        temp[idx++] = array[i];
    }

    for (int i = 0; i < idx; i++)
    {
        array[low + i] = temp[i];
    }
}

void MergeSort(int array[], int low, int high)
{
    if (low == high) return;
    int mid = high / 2;

    MergeSort(array, low, mid);
    MergeSort(array, mid + 1, high);
    Merge(array, low, mid, high);
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    size_t arraySize = 5;
    int* array = new int[arraySize];
    //size_t arraySize = _msize(array) / sizeof(*array);
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "입력(" << i << "): ";
        std::cin >> array[i];
        std::cout << '\n' << array[i];
    }

    MergeSort(array, 0, arraySize - 1);

    //int N, M, V;
    //std::cin >> N >> M >> V;

    //SetAdjVector(N, M, adj);
    //DFS(V);
    //BFS(V);
    //PrintDFS();
    //PrintBFS();

    return 0;
}
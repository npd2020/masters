#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int findMin(int* weight, bool* mark, int n)
{
    int ind = -1;
    int minWeight = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (weight[i] <= minWeight && mark[i] == false)
        {
            ind = i;
            minWeight = weight[i];
        }
    }
    return ind;
}

int main(){
    int n, s, f, v, min;

    cin >> n >> s >> f;
    --s;
    --f;
    int w[n][n];
    int dist[n];
    bool visited[n];

    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    int cur = s;
    dist[cur] = 0;
    visited[cur] = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> w[i][j];
    }

    while (true)
    {
        for (int j = 0; j < n; ++j)
        {
            if (w[cur][j] > 0 && false == visited[j])
            {
                int weightJ = w[cur][j] + dist[cur];
                if (weightJ < dist[j])
                {
                    dist[j] = weightJ;
                }
            }
        }

        cur = findMin(dist, visited, n);

        if (cur == -1)
        {
            break; // path doesnt exist, quit
        }
        else
        {
            visited[cur] = true;
            if (cur == f)
            {
                break; // path found, quit
            }
        }
    }

    if(dist[f] != INT_MAX && cur == f){
        std::cout << dist[f] << std::endl;
    }
    else{
        std::cout << -1 << std::endl;
    }
}

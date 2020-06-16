#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k; 
    vector<int> winner(m);
    for (int i = 0; i < m; i++) // Вершини
    {
        cin >> winner[i];
        winner[i]--; // Зсув індекса, в задачі з 1
    }
    vector<vector<int>> path(n, vector<int>(n, 1e6)); // Матриця сміжності (1е6 = нема ребра)
    for (int i = 0; i < k; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        a--; 
        b--;
        if (path[a][b] > t)
        {
            path[a][b] = t;
            path[b][a] = t;
        }
    }
    int start; // Стартова вершина
    cin >> start;
    start--; 
    vector<int> count(n, 1e6); // Лічильник по шляху до вершини
    vector<bool> used(n, false); // Чи зайшли ми в вершину
    count[start] = 0;
    while (start != -1) // Алгоритм Дейкстри
    {
        int next = -1, mini = 1e6;
        for (int j = 0; j < n; j++)
        {
            if (count[j] > count[start] + path[start][j]) // оновлюємо відстань до сміжних вершин
            {
                count[j] = count[start] + path[start][j];
            }
            if (count[j] < mini && !used[j]) // шукаємо вершину з мін відстанню
            {
                next = j;
                mini = count[j];
            }
        }
        used[start] = true; 
        start = next; // Перехід на наступну вершину
    }
    bool deliver = true; // нехай всі вершини пройдено
    int longest = 0; 
    for (int i = 0; i < m && deliver; i++)
    {
        if (!used[winner[i]]) // чи всім переможцям привезли призи
        {
            deliver = false;
        }
        longest = max(count[winner[i]], longest); // Максимальна відстань (буде доставлено в межах)
    }
    if (deliver) 
    {
        cout << "The good sponsor!\n" << longest << "\n";
    }
    else 
    {
        cout << "It is not fault of sponsor...";
    }
 
    return 0;
}
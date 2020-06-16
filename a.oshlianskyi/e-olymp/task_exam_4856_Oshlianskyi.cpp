#include <iostream> 
#include <vector>
#include <set>
#include <utility>
using namespace std;
#define INF 1000000000000 //нескінченність
#define MAX 100000
 
vector <pair <int, long long> > G[MAX]; //вершини і ребра з них
vector <int> ans;
set <pair <long long, int> > q; // контейнер, куди записуємо черговий елемент
long long length[MAX]; //довжини 
int parent[MAX]; // пращури вершин
 
int main() {
    ios::sync_with_stdio(false); //оптимізуємо швидкість iostream
    int n, m, a, b; //зчитуємо кількість ребер, вершин, початок і кінець
    cin >> n >> m >> a >> b;
    a--, b--; // для зручності розпочинаємо відлік з 0
    for (int i=0; i<m; i++) { //зчитуємо ребра
        int from, to, len;
        cin >> from >> to >> len;
        from--, to--;
        G[to].push_back(make_pair(from, len)); //записуємо вхідне ребро
        G[from].push_back(make_pair (to, len)); //записуємо вихідне ребро
    }
    for (int i=0; i<n; i++) length[i]=INF; //початок реалізації алгоритму Дейкстри - визначаємо величину вершин за нескінченність
    length[a]=0; //початкова вершина
    q.insert (make_pair (length[a], a));
    while (!q.empty()) { // виконуємо допоки черга не буде пустою
        int v = q.begin()->second; //визначаємо вершину
        q.erase (q.begin()); //видаляємо
        for (int i=0; i<G[v].size(); i++) {
            int to=G[v][i].first, len=G[v][i].second;
            if (length[v]+len<length[to]) { // зменшуємо якщо є коротший шлях
                   q.erase (make_pair (length[to], to)); // викидаємо довший шлях і наступну вершину, а замість них
                   length[to]=length[v]+len; 
                   parent[to]=v; 
                   q.insert (make_pair (length[to], to)); // записуємо нову довжину і пращура
            }
        }
    }
    if (length[b]==INF) { // якщо неможливо пройти шлях з a в b
        cout << "-1"; 
        return 0;
    } 
    cout << length[b] << endl; //довжина шляху
    int c=b;
    while (c!=a) {
        ans.push_back(c+1); // визначаємо шлях, повертаючи 1 до номера вершини
        c=parent[c];
    }
    ans.push_back(a+1);
    cout << ans[ans.size()-1];
    for(int it = ans.size()-2; it >=0; it--) cout << " " << ans[it]; //виводимо шлях
    cout << endl;
    return 0;   
}

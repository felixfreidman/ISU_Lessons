#include "pch.h" 
#include <iostream> 
#include <vector> 
using namespace std; 

void Dijkstra(vector<vector<pair<int, int>>>&, int&); 

int main() { 
     setlocale(LC_ALL, "Russian");
/*
Первый элемент пары смежная вершина, а второй элемент - вес инцидентного ребра 
*/
vector<vector<pair<int, int»> G{ 
{ {1, 10}, {2, 6}, {3,8}                              }, // 1 
{ {3, 5}, {4, 13}, {6, 11}                           }, // 2 
{ {4, 3}                                                    }, // 3 
{ {2, 2}, {4, 5}, {5, 7}                               }, // 4 
{ {8, 12}, {5, 9}                                       }, // 5 
{ {7, 8}, {8, 10}                                       }, // 6 
{ {5, 4}, {7, 6}, {8, 16}                            }, // 7
{{8,15}                                                   }, // 8
{                                                             } // 9
}; 
int vortex; 
cout << "Введите номер вершины: "; 
cin >> vortex; 
Dijkstra(G, vortex); 

return 0; 
} 

void Dijkstra(vector<vector<pair<int, int>>>& myG, int& s) { 
// Определяем значение infinity 
const int inf = 2000000000; 
size_t n = myG.size(); 
vector<size_t> D(n, inf); 
vector<size_t> P(n); 
vector<bool> U(n, false); 
// Исходная вершина (в данном случае первая) 
// s = 0; 
D[s] = 0; 
for (size_t i = 0; i < n; i++) { 
// Количество вершин не должно превышать это значение 
size_t v = 1000000000; 
for (size_t j = 0; j < n; j++) 
if (!U[j] && (v == 1000000000 || D[j] < D[v])) 
v = j; 
if (D[v] == inf) 
break; 
// Говорим, что посетили вершину 
U[v] = true; 
// Определяем итераторы по текущему списку 
auto beg = myG[v].begin(); 
auto lst = myG[v].end(); 
while (beg != lst) { 
auto to = beg->first; 
auto len = beg->second; 

if (D[v] + len < D[to]) { 
D[to] = D[v] + len; 
P[to] = v; 
} 
beg++; 
} 
} 
// Выводим список кратчайших маршрутов от 
// исходной вершины ко всем остальным: 
for (auto& r : D) 
cout << r << " "; 
cout << endl; 
}
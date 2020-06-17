#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class vertex{

public:
  int index;
  vector < int > neighbours;
  bool marked;

  vertex(){
   marked = false;
  }
  
  vertex(int ind){
    index = ind;
    marked = false;
  }

  void add_neighbour(int ind_nb){
    neighbours.push_back(ind_nb);
    //cout << index << ": added neighbour " << ind_nb << endl;
  }

  void mark(){
    if (!marked){
    marked = true;
    //cout << index << " - is now marked" << endl;
    }
    else{
      //cout << index << " - was already marked - this shouldn't happen!"	<< endl;
    }
  }
  int num_neighbours(){
    return neighbours.size();
  }

  bool is_marked(){ return marked;}
  int get_index(){ return index;}
  int get_neighbour(int i){
    return neighbours[i];
  }

};

queue < vertex > q;
vector<int> passed;

int main(){
  
  int N, M, v;
  cin >> N >> M >> v;
  
  vector < vertex > vertices (N);
  for (int i=0; i<N; i++){
    vertices[i].index = i+1;
  }

  int v1, v2;

  for (int i=0; i<M; i++){
    cin >> v1 >> v2;
    vertices[v1-1].add_neighbour(v2); 
    vertices[v2-1].add_neighbour(v1);
  }
  
  //  queue < vertex > q;
  q.push (vertices[v-1]);
  vertices[v-1].mark();
  
  //  vector<int> passed;
  passed.push_back(v);
  
  vertex vtx;
  vertex *to;
  while (!q.empty()) {
    vtx = q.front();
    q.pop();
    for (int i=0; i<vtx.num_neighbours(); i++) {
      to =&(vertices[vtx.get_neighbour(i)-1]);
      if (!to->is_marked()) {
	to->mark();
	q.push (*to);
	passed.push_back(to->get_index());
      }
    }
  }

  cout << passed.size() << endl;
  for (int i=0; i<passed.size(); i++){
    cout << passed[i] << " ";
  }
  cout << endl;
  
  return 0;
}

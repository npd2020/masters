#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class vertex{

public:
  int index, distance;
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
  void set_dist(int d){distance = d;}
  int get_dist(){ return distance;}
  
};

//queue < vertex > q;
vector<int> passed;
vector < vertex > vertices;

int main(){
  
  int N, M; //, v, v_to;
  cin >> N >> M; // >> v >> v_to;
  
  vector < vertex > vertices0 (N);
  for (int i=0; i<N; i++){
    vertices0[i].index = i+1;
  }

  int v1, v2;

  for (int i=0; i<M; i++){
    cin >> v1 >> v2;
    vertices0[v1-1].add_neighbour(v2); 
    vertices0[v2-1].add_neighbour(v1);
  }

  int sum=0;
  for (int v=1; v<N+1; v++){

    //    vector < vertex > vertices = vertices0;
    vertices = vertices0;
    queue < vertex > q;
    //    vector<int> passed;
    
    //    cout<<"for v = "<<v<<":"<<endl;
    
    q.push (vertices[v-1]);
    vertices[v-1].mark();
    vertices[v-1].set_dist(0);
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
	  to->set_dist(vtx.get_dist()+1);
	  q.push (*to);
	  passed.push_back(to->get_index());
	}
      }
    }

    //  sum += passed.size();
    //    cout << passed.size() << endl;
    //   for (int i=0; i<passed.size(); i++){
    //      cout << passed[i] << " ";
    //    }
    //   cout << endl;
    for (int i=0; i<vertices.size(); i++){
      //      cout << vertices[i].get_index()<<"--"<<vertices[i].get_dist() << " ";
      sum += vertices[i].get_dist();
    }
    //    cout << endl;
    passed.clear();
    vertices.clear();
    //    std::queue<int>().swap(q);
  }
  cout <<sum<<endl;
  return 0;
}

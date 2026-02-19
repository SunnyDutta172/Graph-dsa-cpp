//Graph is basically a network of nodes.
//The nodes are connected to each other through Edges.
//In graph, the nodes are called vertex. And many vertex are called Vertices. 
//Graphs are used in OLA, UBER, GOOGLE MAPS. We can also visualize our social network connections through Graphs.
//Types of graphs based on edges are:- unidirectional graph and undirected graph(bidirectional graph).--> directed and undirected graphs.
//If any value is given to edges then that graph becomes weighted graph.(value can either be +ve or -ve).
//If any value is not associated with edges then that graph becomes unweighted graph.
//From all this discussion we can conclude another 4 types of graphs and they are: 1)undirected unweighted graph. 2)undirected weighted graph. 3)directed weighted graph. 4)directed unweighted graph.
//There is also a type of graph which are called Disconnected graph.
//In cpp stl, we have list and it is actually a doubly linked list. It has various functions like it can push_back,push_front,pop_back,pop_front,it can calculate the size from size().
//We will use Adjacency List to introduce graphs in cpp. We will use E for edges and V for vertices.
//Adjacency list means to store neighbours for all V(vertices).
/* 0     2          list<int>[V]
    \   /  \        0 -> [1] -> list<int>
      1  -- 3       1 -> [0,2,3] -> list<int>
                    2 -> [1,3] -> list<int>
                    3 -> [1,2] -> list<int>
      we can use vector of size V to initialize the graph that is: vector<list<int>> or an array of size V: arr<list<int>>
*/                  
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Graph{
  int V;
  list<int> *l; //int *arr

public:
  Graph(int V){
    this->V = V;
    l = new list<int> [V]; // arr = new int[V]
  }
  void addEdge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }
  void printAdjList(){
    for(int i=0; i<V; i++){
      cout << i << ":";
      for(int neigh : l[i]){
        cout << neigh << " ";
      }
      cout << endl;
    }
  } 
};
int main(){
  Graph g(5);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(2,3);
  g.addEdge(2,4);

  g.printAdjList();
return 0;
}

//BFS - Breadth First Search --> Travel to immediate neighbours first.
//We have to track the visited node otherwise we will fall for a loop.When we visit any node we will mark it to asVisited.
//We use a Queue for BFS Traversal.and we also use a boolean array for isVisited purpose.We will initialized to false value to the boolean array.
//We will start with a source node and when visited we will add that to the queue and make the isVisited true for that respective node.
//We will take Source Node as 'u' and destination node as 'v'.
//We will also use a while loop to pop all the elements in the queue. the while loop will continue until the queue becomes empty.and it will mean that we visited every node.
//while(Q.size > 0){
// int u = Q.pop() //source node
//cout << u;
//for(all neighbours of u){
//  if(!vis[v])
//1) vis[v] = true;
//2)Q.push(v);
//}
//}
#include <iostream>
#include <vector>
#include <list>
#include <queue>
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
  //BFS Traversal
  void bfs(){ //O(V+E) is the Worst case Time Complexity
    queue<int> Q;
    vector<bool> vis(V, false); //vector names vis of size V and all values are initialized as false.
    Q.push(0); // 0 is the source node here
    vis[0] = true; //Mark 0 as visited

    while(Q.size() > 0){
        int u = Q.front(); // u-> Source Node
        Q.pop();
        cout << u << " ";

        for(int v: l[u]){ // v-> Immediate Neighbour
            if(!vis[v]){
                vis[v] = true;
                Q.push(v);
            }
        }
    }
    cout << endl;
  }
};
int main(){
  Graph g(5);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(2,3);
  g.addEdge(2,4);

  g.bfs();
return 0;
}

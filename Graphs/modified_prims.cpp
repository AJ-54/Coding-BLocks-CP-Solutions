#include<bits/stdc++.h>
#define inf 1e9
#define endl '\n'
using namespace std;

// Structure to represent a min heap node 
struct MinHeapNode { 
    int v; 
    int key; 
}; 
  
// Structure to represent a min heap 
struct MinHeap { 
    int size; // Number of heap nodes present currently 
    int capacity; // Capacity of min heap 
    int* pos; // This is needed for decreaseKey() 
    struct MinHeapNode** array; 
}; 
  
// A utility function to create a new Min Heap Node 
struct MinHeapNode* newMinHeapNode(int v, int key) 
{ 
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
    minHeapNode->v = v; 
    minHeapNode->key = key; 
    return minHeapNode; 
} 
  
// A utilit function to create a Min Heap 
struct MinHeap* createMinHeap(int capacity) 
{ 
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
    minHeap->pos = (int*)malloc(capacity * sizeof(int)); 
    minHeap->size = 0; 
    minHeap->capacity = capacity; 
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 
  
// A utility function to swap two nodes of min heap. Needed for min heapify 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{ 
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
} 
  
// A standard function to heapify at given idx 
// This function also updates position of nodes when they are swapped. 
// Position is needed for decreaseKey() 
void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
    int smallest, left, right; 
    smallest = idx; 
    left = 2 * idx + 1; 
    right = 2 * idx + 2; 
  
    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key) 
        smallest = left; 
  
    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key) 
        smallest = right; 
  
    if (smallest != idx) { 
        // The nodes to be swapped in min heap 
        MinHeapNode* smallestNode = minHeap->array[smallest]; 
        MinHeapNode* idxNode = minHeap->array[idx]; 
  
        // Swap positions 
        minHeap->pos[smallestNode->v] = idx; 
        minHeap->pos[idxNode->v] = smallest; 
  
        // Swap nodes 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
  
        minHeapify(minHeap, smallest); 
    } 
} 
  
// A utility function to check if the given minHeap is ampty or not 
int isEmpty(struct MinHeap* minHeap) 
{ 
    return minHeap->size == 0; 
} 
  
// Standard function to extract minimum node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
    if (isEmpty(minHeap)) 
        return NULL; 
  
    // Store the root node 
    struct MinHeapNode* root = minHeap->array[0]; 
  
    // Replace root node with last node 
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1]; 
    minHeap->array[0] = lastNode; 
  
    // Update position of last node 
    minHeap->pos[root->v] = minHeap->size - 1; 
    minHeap->pos[lastNode->v] = 0; 
  
    // Reduce heap size and heapify root 
    --minHeap->size; 
    minHeapify(minHeap, 0); 
  
    return root; 
} 
  
// Function to decrease key value of a given vertex v. This function 
// uses pos[] of min heap to get the current index of node in min heap 
void decreaseKey(struct MinHeap* minHeap, int v, int key) 
{ 
    // Get the index of v in  heap array 
    int i = minHeap->pos[v]; 
  
    // Get the node and update its key value 
    minHeap->array[i]->key = key; 
  
    // Travel up while the complete tree is not hepified. 
    // This is a O(Logn) loop 
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) { 
        // Swap this node with its parent 
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2; 
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i; 
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]); 
  
        // move to parent index 
        i = (i - 1) / 2; 
    } 
} 
  
// A utility function to check if a given vertex 
// 'v' is in min heap or not 
bool isInMinHeap(struct MinHeap* minHeap, int v) 
{ 
    if (minHeap->pos[v] < minHeap->size) 
        return true; 
    return false; 
} 

class Graph{
    public:
    int v;
    list<pair<int,int>> *adjList;
    Graph(int z){
        this->v = z+1;
        adjList = new list<pair<int,int>>[v];
    }

    void addEdge(int u,int v, int w, bool bidir = true){
        adjList[u].push_back(make_pair(v,w));
        if (bidir){
            adjList[v].push_back(make_pair(u,w));
        }
    }

    int findMinVertex(int* weight, bool* visited, int v){
        int minvertex = -1;    
        for(int i=0;i<v;i++){
            if (!visited[i] && (minvertex == -1 || weight[i] < weight[minvertex])){
                minvertex = i;
            }
        }
        return minvertex;   
    }

    void Prims(){
        bool *visited = new bool[v];
        int *parent = new int[v];
        int *weight = new int[v];

        //Create MinHeap
        struct MinHeap* minHeap = createMinHeap(v); 

        for(int i=0;i<v;i++){
            visited[i] = 0;
            weight[i] = inf;
        }
        weight[1] = 0;
        parent[1] = -1;
        for(int i=1;i<v;i++){
            int minvertex = findMinVertex(weight, visited, v);
            visited[minvertex] = 1;
            for(auto neighbour:adjList[minvertex]){
                if (!visited[neighbour.first]){
                    if (weight[neighbour.first] > neighbour.second){
                        weight[neighbour.first] = neighbour.second;
                        parent[neighbour.first] = minvertex;    
                    }
                }
            }
        }
        int tw = 0;
        for(int i=1;i<v;i++){
            tw += weight[i];
            cout << i << "--" << parent[i] << " has weight " << weight[i] << endl;
        }
        cout << tw << endl;
    }   
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,e;
    cin >> n >> e;
    Graph g(n);
    for(int i=0;i<e;i++){
        int s,d,w;
        cin >> s >> d >> w;
        g.addEdge(s,d,w);
    }
    g.Prims();
}
/*BFS algorithm in C, also known as the Breadth-First Search algorithm is commonly used as a searching, traversing algorithm in graphs, trees, multidimensional arrays, or in general recursion. BFS program in C is implemented by using a queue data structure to perform the basic characteristic of the BFS algorithm that is traversing level-wise. BFS algorithm is usually used to find the shorted path or the nearest neighbor element in a graph or tree.*/

/*To implement the BFS algorithm in C users need to store the nodes which are already visited but not processed, for this we will store them in a queue which will provide us the FIFO property (First in First Out). Also, we need to maintain the nodes which are visited, to escape revisiting and reprocessing them. So we will maintain an array to mark visited nodes.

Algorithm:

Initially, we will add the initial node from where we have to start the search and mark it visited in the visited array.
Run the while loop until the queue is non-empty.
At each iteration, find all the connected nodes to the front element of the queue.
If the connected nodes to the front elements are already visited then do noting
Else, mark them visited in the visited array and push them into the queue.
Note: These are the basic steps of the BFS in C algorithm, now we can add some special points into the implementation like: If we are searching for a special node then we can end the while loop when we reach the required node.*/

#include<stdio.h>

// creating queue data structure using arrays
int queue[100];

// defining pointers of the queue to perform pop and push
int front=0,back=0;

// defining push operation on the queue
void push(int var)
{
    queue[back] = var;
    back++;
}

// defining pop operation on queue
void pop()
{
    queue[front] = 0;
    front++;
}

// creating a visited array to keep the track of visited nodes
int visited[7] = {0};

int main()
{
    // defining the number of total persons 
    int N  = 6;

    // adjacenty matrix representing graph
    int graph[6][6] = {{0,1,1,0,0,0},
                     {1,0,1,0,0,0},
                     {1,1,0,1,1,0},
                     {0,0,1,0,0,0},
                     {0,0,1,0,0,1},
                     {0,0,0,0,1,0}};
    
    // front == back stands for empty queue 
    // until queue is not empty perfroming bfs 


    // adding a starting node in the list 
    push(1);
    visited[0] = 1; // marking 1st node as visited 
    while(front != back)
    {
        int current = queue[front];
        
        // printing current element 
        printf("%d ", current);
        
        // popping the front element from the queue
        pop();
 
        for(int i=0;i<6;i++)
        {
            // adding non-visited connected nodes of the current node to the queue 
            if((graph[current-1][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1; // marking visisted
                push(i+1);
            }
        }
    }
    return 0;
}

#ifndef JSS136_316P4_HPP_INCLUDED
#define JSS136_316P4_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int SIZEARRAY = 100;
//For priority Queue
struct item{
    int item;
    int priority;
};

//For adjecency List
struct AdjListNode{
    int nextVertex;
    int weight;
    AdjListNode *next;
};

AdjListNode* createNode(int toVertex, int wht){
    AdjListNode *newNode = new AdjListNode;
    newNode->nextVertex = toVertex;
    newNode->weight = wht;
    newNode->next = nullptr;

    return newNode;
}

struct AdjList{
    AdjListNode *head; //beginning of each list
};

struct Graph{
    int numVertex;
    AdjList *array; //an array of heads to a list
};

Graph* createGraph(int numVertex){
    Graph *newGraph = new Graph;
    newGraph->numVertex = numVertex;

    newGraph->array = new AdjList;

    //Initialize graph as empty
    for(int i = 0; i < numVertex; ++i)
        newGraph->array[i].head = nullptr; //may need to change . to ->

    return newGraph;
}

void addEdge(Graph *graph, int startVert, int endVert, int weight){
    AdjListNode *newNode = createNode(endVert, weight);
    newNode->next = graph->array[startVert].head;
    graph->array[startVert].head = newNode;

    newNode = createNode(startVert, weight);
    newNode->next = graph->array[endVert].head;
    graph->array[endVert].head = newNode;

}

void CreateAdjList(){
    //This function will read from the text file and fill in
    //the adjacency list structure
    ifstream fileObj;
    string filename;
    int numVertex, currentVert, nextVert, wht;

    cout << "Enter the path to the text file you wish to open:";
    cin >> filename;

    fileObj.open(filename);

    if(!fileObj){
        cerr << "File was not opened correctly...Returning to menu\n";
        return;
    }
    fileObj >> numVertex;

    //create an empty adj list
    Graph *graph = createGraph(numVertex);

    //now begin filling list with edges in the text file
    while(!fileObj.eof()){
        fileObj >> currentVert;
        fileObj >> nextVert;
        fileObj >> wht;

        addEdge(graph, currentVert, nextVert, wht);
    }
    cout << "Adjacency list has been created to represent an undirected graph\n";

}
#endif // 136_316P4_HPP_INCLUDED


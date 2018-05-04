#ifndef 136_316P4_HPP_INCLUDED
#define 136_316P4_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

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

void createNode(int, int, int){

}

struct AdjList{
    AdjListNode *head; //beginning of list
};


//Adjecency List
struct Graph{
    int numVertex;
    AdjList *array;
};

Graph createGraph(int numVertex){



    return ;
}


void CreateAdjList(){
    //This function will read from the text file and fill in
    //the adjacency list structure
    ifstream fileObj;
    string filename;
    int numVertex, currentVert, nextVert, wht;

    cout << "Enter the name of the path to the text file you want to open:";
    cin >> filename;

    fileObj.open(filename);

    if(!fileObj){
        cerr << "File was not opened correctly...Returning to menu\n";
        return;
    }
    fileObj >> numVertex;

    Graph *graph = createGraph(numVertex);

    while(!fileObj.eof()){
        fileObj >> currentVert;
        fileObj >> nextVert;
        fileObj >> wht;

        AdjListNode newNode;

        newNode = createNode(currentVert, nextVert, wht);

        addNode(newNode);




    }

}
#endif // 136_316P4_HPP_INCLUDED

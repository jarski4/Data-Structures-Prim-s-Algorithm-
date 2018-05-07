/*
   COPYRIGHT (C) 2018 Jared Skinner (jss136) All rights reserved.
   Data Structures Project #4
   Author.  Jared Skinner
            jss136@zips.uakron.edu
   Version. 1.01 05.05.2018
   Purpose: Find a minimum spanning tree based on Prim's algorithm
   and use a non-recursive Depth First Traversal function to
   print out all the vertices.
*/
/*
This program assumes the test file is formatted as...

9       <--------# of vertices in undirected graph
1 2 3   <--------following lines are pair of vertices(edge) and its weight
5 6 7
.
.
.

*/

#include <iostream>
#include "136_316p4.hpp"

using namespace std;

int main(){
    int menuChoice, totalVert, startInd;
    bool stillGoing = true;


    cout << "(1) Find MST\n" << "(2) Depth First Traversal\n"
        << "(3) Quit\n";

    cout << "Before selecting a menu option you must include\nwhich file contains"
        << " your undirected graph.\n";

    ifstream fileObj;
    string filename;
    int origin, dest, weight;

    cout << "Enter name of file you wish to open: ";
    cin >> filename;

    fileObj.open(filename);

    if(!fileObj){
        cerr << "File didn't open correctly. Try again.\n";
        return 4;
    }
    else
        cout << "File opened successfully...\n\n";

    fileObj >> totalVert;
    struct Graph* graph = createGraph(totalVert);

    while(!fileObj.eof()){
        fileObj >> origin;
        fileObj >> dest;
        fileObj >> weight;

        addEdge(graph, origin, dest, weight);
    }
    cout << "Adjacency List successfully created to represent your graph...\n\n";

    //menu
    do{
        cout << "Select your menu choice: ";
        cin >> menuChoice;

        switch(menuChoice){
            case 1:{
                PrimMST(graph);
                break;
            }
            case 2:{
                cout << "To begin depth first traversal, which vertex do you want to start at?\n"
                    << "The vertex indices start at 0: ";
                cin >>startInd;
                DepthFirst(graph, startInd);
                break;
            }
            case 3:{
                stillGoing = false;
                cout << "Program is ending....\n";
                break;
            }
        }
    }while((stillGoing == true));
    return 0;
}

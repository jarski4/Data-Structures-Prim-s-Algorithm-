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

#include <iostream>
#include "136_316p4.hpp"


using namespace std;

int main(){
    int menuChoice = 0, startVert;
    bool stillGoing = true;

    cout << "(1) Find MST\n" << "(2) Depth First Traversal\n"
        << "(3) Quit\n";

    //create a menu
    do{
        cout << "Select your choice: ";
        cin >> menuChoice;

        switch(menuChoice){
            case 1:{
                CreateAdjList(); //First create the adjacency list before creating Min Span Tree
                //MinSpanTree();
                break;
                }
            case 2:{
                cout << "Which vertex do you want to start at?: \n";
                cin >> startVert;
                startVert-=1;

                //DepthFirstTrav();
                break;
                }
            case 3:{
                stillGoing = false;
                cout << "Program is ending....";
                break;
                }
        }
    }while((stillGoing = true));

    return 1;
}

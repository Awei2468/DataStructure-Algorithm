#include<iostream>
#include<iomanip>
#include<stack>
#include "memory.h"     //for memcpy

using namespace std;

const int Exit_X = 13, Exit_Y = 10;
const int X_axis = 15, Y_axis = 12;

int Maze[X_axis][Y_axis] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1,
                            1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1,
                            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
                            1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
                            1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1,
                            1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1,
                            1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
                            1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1,
                            1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
                            1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int MazeCopy[X_axis][Y_axis];                                                   

struct Node
{
    int x, y;
    Node(int x1, int y1):x(x1),y(y1){};
    Node *next;
};

class PathList
{
    private:
        Node *pathStart;
    public:
        PathList():pathStart(NULL){};
        void pathPush(int x, int y);
        void pathPop(int &x, int &y);
        bool CheckExit(int x, int y, int exit_x, int exit_y);

};

void PathList::pathPush(int x, int y){  //stack push
    
    Node *newNode = new Node(x,y);
    
    if (!pathStart) {
       pathStart = newNode;
    }
    else {
        newNode->next = pathStart;
        pathStart = newNode;
    }  

}

void PathList::pathPop(int &x, int &y){  //stack pop

    Node *deleteNode = pathStart;

    if (!pathStart) 
        return;
    else {
        pathStart =  pathStart->next;
        x = pathStart->x;
        y = pathStart->y;
        delete deleteNode;
        deleteNode = NULL;
    }
    
}

bool PathList::CheckExit(int x, int y, int exit_x, int exit_y){

    if (x == exit_x && y == exit_y) {
        if (Maze[x][y+1] == 2 || Maze[x][y-1] == 2 || Maze[x+1][y] == 2 || Maze[x-1][y] == 2)
            return true;
    }
    return false;
}

int VisitMaze(int A[][Y_axis], int i, int j, int &check);

int main(){

    int x = 1, y = 0;
    bool check  = false;
    int end = 0;  //for recursive use
    PathList P1;

    cout << "Before1:" << endl;
    for (int i = 0; i < X_axis; ++i) {  //print initialize value
        for (int j = 0; j < Y_axis; ++j) {
            cout << setw(2) << Maze[i][j];
        }
        cout << endl;
    }

    memcpy(MazeCopy,Maze,sizeof(Maze));

    while (true) {  //use while loop + stack
        if (y+1 < Y_axis && Maze[x][y+1] == 0) {  //right
            Maze[x][y+1] = 2;
            check = true;
            y += 1;
        }
        else if (y-1 >= 0 && Maze[x][y-1] == 0) {  //left
            Maze[x][y-1] = 2;
            check = true;
            y -= 1;
        }
        else if (x+1 < X_axis && Maze[x+1][y] == 0) {  //down
            Maze[x+1][y] = 2;
            check = true;
            x += 1;
        }
        else if (x-1 >= 0 && Maze[x-1][y] == 0) {  //up
            Maze[x-1][y] = 2;
            check = true;
            x -= 1;
        }
        else {  //no road
            check = false;
            Maze[x][y] = 4;  //dead road
        }

        if (check) {
            P1.pathPush(x,y);
        }
        else {
            P1.pathPop(x,y);
        }

        if (x == Exit_X && y == Exit_Y)  //find exit
            break;
    }

    cout << "After1:" << endl;
    for (int i = 0; i < X_axis; ++i) {  //print initialize value
        for (int j = 0; j < Y_axis; ++j) {
            cout << setw(2) << Maze[i][j];
        }
        cout << endl;
    }

    cout << "Before2:" << endl;
    for (int i = 0; i < X_axis; ++i) {  //print initialize value
        for (int j = 0; j < Y_axis; ++j) {
            cout << setw(2) << MazeCopy[i][j];
        }
        cout << endl;
    }

    if (VisitMaze(MazeCopy, 1, 1, end))
        cout << "End of Maze!" << endl;

    cout << "After2:" << endl;
    for (int i = 0; i < X_axis; ++i) {  //print initialize value
        for (int j = 0; j < Y_axis; ++j) {
            cout << setw(2) << MazeCopy[i][j];
        }
        cout << endl;
    }

    system("pause");
    return 0;
}

int VisitMaze(int A[][Y_axis], int i, int j, int &check){  //recursive

    A[i][j] = 2;

    if (i == Exit_X && j == Exit_Y) {
        check = 1;
    }

    if (check != 1 && j+1 < Y_axis && A[i][j+1] == 0) {  //right
        if (VisitMaze(A,i,j+1,check) == 1)
            return 1;
    }
    if (check != 1 && j-1 >= 0 && A[i][j-1] == 0) {  //left
        if (VisitMaze(A,i,j-1,check) == 1)
            return 1;
    }
    if (check != 1 && i+1 < X_axis && A[i+1][j] == 0) {  //down
        if (VisitMaze(A,i+1,j,check) == 1)
            return 1;
    }
    if (check != 1 && i-1 >= 0 && A[i-1][j] == 0) {  //up
        if (VisitMaze(A,i-1,j,check) == 1)
            return 1;
    }
    if (check != 1) {  //dead road
        A[i][j] = 4;
    }

    return check;
}
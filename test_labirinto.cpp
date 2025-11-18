#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

const char p = 'O';
char labirinto[12][12] = {
        //0---1---2---3---4---5---6---7---8---9---10--11
    /*0*/{'#',' ','#','#','#','#','#','#','#','#','#','#'},
    /*1*/{'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    /*2*/{'#',' ','#',' ','#',' ','#',' ','#','#',' ','#'},
    /*3*/{'#',' ','#','#','#',' ','#','#',' ',' ',' ','#'},
    /*4*/{'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
    /*5*/{'#','#','#','#','#',' ','#','#','#',' ',' ','#'},
    /*6*/{'#',' ',' ','#',' ',' ','#',' ',' ',' ','#','#'},
    /*7*/{'#',' ','#',' ',' ','#','#',' ','#',' ',' ','#'},
    /*8*/{'#',' ',' ',' ','#',' ','#',' ','#',' ',' ','#'},
    /*9*/{'#',' ','#','#',' ',' ',' ',' ','#',' ',' ','#'},
    /*10*/{'#',' ',' ','#',' ',' ','#',' ','#','#','#','#'},
    /*11*/{'#','#','#','#',' ','#','#','#','#','#','#','#'}
    };


void move(int &x, int &y) {
    int ritorno;
    int x_precedente = x;
    int y_precedente = y;
    while (!kbhit())
    {
        
    }
    char mossa = getch();
    switch (mossa)
    {
    case 'w':
        if(labirinto[y-1][x] != ' ') {
            return;
        }
        else {
            y-=1;
        }
        break;

    case 's':
        if (labirinto[y+1][x] != ' ') {
            return;
        }
        else {
            y+=1;
        }
        break;
    
    case 'd':
        if (labirinto[y][x+1] != ' ') {
            return;
            }
        else {
            x+=1;
        }
        break;
    
    case 'a':
        if (labirinto[y][x-1] != ' ') {
            
            return;
        }
        else {
            x-=1;
        }
        break;
    default:
        
        break;
    }
    labirinto[y_precedente][x_precedente] = ' ';
    return;
}

void show(int x, int y) {
    labirinto[y][x] = p;
    for(int i = 0;i<12; i++) {
        for(int g = 0; g < 12; g++) {
            cout << labirinto[i][g];
        }
        cout << endl;
    }
    
}


int main() {

    int x=1,y=0;
    while (true)
    {
        show(x,y);
        move(x,y);
        cout << "X = " << x << " Y = " << y << endl;
        if (x == 4 && y == 11)
        {   
            Sleep(500);
            cout << "hai vinto!" << endl;
            break;
        }
        
        system("cls");
    }
    cout << "premi un tasto per terminare il programma" << endl;

    while (!kbhit()) {

    }
    
    return 0;
}
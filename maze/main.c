/*
26. Crea un gioco che utilizza una matrice per rappresentare un labirinto, in cui il
giocatore deve trovare un percorso per uscire. Traccia: Crea una matrice che
rappresenti il labirinto, con celle che rappresentano le pareti e il percorso.
Implementa la logica del gioco in modo che il giocatore possa muoversi nel
labirinto e trovare un percorso per raggiungere l'uscita. Puoi utilizzare un
algoritmo di ricerca come la ricerca in profondità o la ricerca in ampiezza per
trovare il percorso.
*/

#include <stdio.h>
#define SIZE 6

int move(char maze[SIZE][SIZE],int pos[2],char move){
    if(move=='w'){
        if(pos[0]-1<0){
            return -1;
        }
        if(maze[pos[0]-1][pos[1]]=='x'){
            return -1;
        }else if(maze[pos[0]-1][pos[1]]==' '){
            maze[pos[0]][pos[1]] = ' ';
            maze[pos[0]-1][pos[1]] = 'P';
            pos[0]--;
            return 0;
        }else if(maze[pos[0]-1][pos[1]]=='E'){
            maze[pos[0]][pos[1]] = ' ';
            maze[pos[0]-1][pos[1]] = 'P';
            pos[0]--;
            return 1;
        }
    }
    if(move=='s'){
        if(pos[0]+1>=SIZE){
            return -1;
        }
        if(maze[pos[0]+1][pos[1]]=='x'){
            return -1;
        }else if(maze[pos[0]+1][pos[1]]==' '){
            maze[pos[0]][pos[1]] = ' ';
            maze[pos[0]+1][pos[1]] = 'P';
            pos[0]++;
            return 0;
        }else if(maze[pos[0]+1][pos[1]]=='E'){
            maze[pos[0]][pos[1]] = ' ';
            maze[pos[0]+1][pos[1]] = 'P';
            pos[0]++;
            return 1;
        }
        

    }
    if(move=='a'){
        if(pos[1]-1<0){
            return -1;
        }
        if(maze[pos[0]][pos[1]-1]=='x'){
            return -1;
        }else if(maze[pos[0]][pos[1]-1]==' '){
            maze[pos[0]][pos[1]] = ' ';
            maze[pos[0]][pos[1]-1] = 'P';
            pos[1]--;
            return 0;
        }else if(maze[pos[0]][pos[1]-1]=='E'){
            maze[pos[0]][pos[1]] = ' ';
            maze[pos[0]][pos[1]-1] = 'P';
            pos[1]--;
            return 1;
        }
        

    }
    if(move=='d'){
        if(pos[1]+1>=SIZE){
            return -1;
        }
        if(maze[pos[0]][pos[1]+1]=='x'){
            return -1;
        }else if(maze[pos[0]][pos[1]+1]==' '){
            maze[pos[0]][pos[1]] = ' ';
            maze[pos[0]][pos[1]+1] = 'P';
            pos[1]++;
            return 0;
        }else if(maze[pos[0]][pos[1]+1]=='E'){
            maze[pos[0]][pos[1]] = ' ';
            maze[pos[0]][pos[1]+1] = 'P';
            pos[1]++;
            return 1;
        }
        

    }
} //1 successo, 0 fail

void printMaze(char maze[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
}
int main(void){
    char maze[SIZE][SIZE] = {
        {'x','x','x','x','P','x'},
        {'x','x','x','x',' ','x'},
        {'x',' ',' ',' ',' ','x'},
        {'x',' ','x','x','x','x'},
        {'E',' ','x','x','x','x'},
        {'x','x','x','x','x','x'}
    };
    int pos[2] = {0,4};
    char mov = ' ';
    while(mov!='e'){
        printMaze(maze);
        scanf("%c",&mov);
        if(move(maze,pos,mov)==1){
            printf("\033[H\033[J");
            printMaze(maze);
            printf("\nVictory");
            break;
        };
        printf("\033[H\033[J");//clears the screen


    }
}
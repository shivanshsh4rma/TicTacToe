#include<bits/stdc++.h>
using namespace std;
#define P1 1
#define P2 2
#define P1MOVE 'O'
#define P2MOVE 'X'
void showBoard(char board[][3]){
cout<<"                              "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
cout<<"                              -----------"<<endl;
cout<<"                              "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
cout<<"                              -----------"<<endl;
cout<<"                              "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;}
void showInstructions(){
cout<<"Choose a cell numbered from 1 to 9 as below and play"<<endl;
cout<<endl;
cout<<"                                1 | 2 | 3  "<<endl;
cout<<"                              -------------"<<endl;
cout<<"                                4 | 5 | 6  "<<endl;
cout<<"                              -------------"<<endl;
cout<<"                                7 | 8 | 9  "<<endl;
cout<<endl;
}
void initialise(char board[][3]){
for (int i=0; i<3; i++){
for (int j=0; j<3; j++)
board[i][j] = '*';}
}
void declareWinner(int whoseTurn){
if (whoseTurn == P1)
cout<<"Player1(O) won the game"<<endl;
else
cout<<"Player2(X) won the game"<<endl;
}
bool rowCrossed(char board[][3]){
for (int i=0; i<3; i++){
if (board[i][0] == board[i][1] &&
board[i][1] == board[i][2] &&
board[i][0] != '*')
return (true);
}
return(false);
}
bool columnCrossed(char board[][3]){
for (int i=0; i<3; i++){
if (board[0][i] == board[1][i] &&
board[1][i] == board[2][i] &&
board[0][i] != '*')
return (true);
}
return(false);
}
bool diagonalCrossed(char board[][3]){
if (board[0][0] == board[1][1] &&
board[1][1] == board[2][2] &&
board[0][0] != '*')
return(true);
if (board[0][2] == board[1][1] &&
board[1][1] == board[2][0] &&
board[0][2] != '*')
return(true);
return(false);
}
bool gameOver(char board[][3]){
return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board) );
}
int gt=0;
void playTicTacToe(){
int whoseTurn=P1;
char board[3][3];
int moveIndex=0, x=0, y=0;
initialise(board);
showInstructions();
while (gameOver(board) == false && moveIndex != 3*3){
int n;
cout<<"Blank spaces where you can insert: ";
for(int i=0; i<3; i++)
for (int j = 0; j < 3; j++){
if (board[i][j] == '*')
cout<<(i*3+j)+1<<" ";}
cout<<endl;
cout<<"So, where would you like to put your mark? ";
if (whoseTurn == P1){
cout<<"(Player1(O) to move)"<<endl;}
else{
cout<<"(Player2(X) to move)"<<endl; 
}
cin>>n;
n--;
x=n/3;
y=n%3;
if(board[x][y] == '*' && n<9 && n>=0){
if(whoseTurn == P1){
board[x][y] = P1MOVE;}
else{
board[x][y] = P2MOVE; 
}
cout<<"Your mark goes at position: "<<n+1<<endl;
showBoard(board);
moveIndex ++;
}
else{
    cout<<"Invalid Move"<<endl;
    gt=1;
    break;
}
if(whoseTurn == P1){
whoseTurn = P2;}
else{
whoseTurn = P1;}
}
if(gt==1){
    cout<<"Game finished"<<endl;
}
else if(gameOver(board) == false && moveIndex == 9){
cout<<"Draw it is!"<<endl;}
else{
    if (whoseTurn == P1)
        whoseTurn = P2;
    else if (whoseTurn == P2)
        whoseTurn = P1;
    declareWinner(whoseTurn);
}
}
int main(){
cout<<"Welcome to Tic Tac Toe"<<endl;
char pa='y';
while(pa=='y'){
playTicTacToe();
cout<<"Play again?(y/n)"<<endl;
cin>>pa;
}
cout<<"Alright, Have a good one"<<endl;
return 0;
}
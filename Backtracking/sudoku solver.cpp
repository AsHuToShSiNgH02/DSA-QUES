#include <iostream>
#include <vector>
using namespace std;

bool canWePlace(vector<vector<char>> & board,int row,int col,char num){
        //is that num present in particular row
        for(int i = 0;i<9;i++){
            if(board[i][col]==num) return false;
        }
        //is that num present in particular col
        for(int j = 0;j<9;j++){
            if(board[row][j]==num) return false;
        }
        //is that num present in particular sub vector of 3x3
        int r = (row/3)*3; //big row
        int c = (col/3)*3; //big col
        for(int i = r;i<(r+3);i++){
            for(int j = c;j<(c+3);j++){
                if(board[i][j]==num) return false;
            }
        }
        return true;
    }
    bool sudoku(int row,int col,vector<vector<char>>& board){
        //base condition
        //when col = 9 that means one complete row is filled so move to nxt row
        if(col==9) return sudoku(row+1,0,board);
        //when row = 9 that measn sudoku is complete
        if(row==9) return true;
        
        if(board[row][col] == '.'){
            //chk for all num from 1 to 9 which is suitable for which box
            for(int num = 1;num<=9;num++){
                //convert that num into char then chk weather we can place or not
                if(canWePlace(board,row,col,'0'+ num)){
                    //place the num
                    board[row][col] = '0'+num;
                    //place the num and move ahead in col
                    bool res = sudoku(row,col+1,board);
                    //if sudouku is solved then return true
                    if(res) return true;
                    //revert the condition
                    board[row][col] = '.';
                }
            }
            return false;
        }else{
            //if at row,col already exist a num then move forward
            return sudoku(row,col+1,board);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(0,0,board);
    }

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    solveSudoku(board);
    
    // Output the solved Sudoku board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
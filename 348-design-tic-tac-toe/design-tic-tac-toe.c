


typedef struct {
 
    int size;
    int** val;
} TicTacToe;


TicTacToe* ticTacToeCreate(int n) {
    TicTacToe* t=(TicTacToe*)malloc(sizeof(TicTacToe));
    t->val = (int**)malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        t->val[i]=(int*)calloc(n,sizeof(int));
    }
    t->size=n;
    return t;
}


int check(TicTacToe* obj,int row,int col,int n){
    int x=obj->val[row][col];
    bool win=true;
    for(int i=0;i<n;i++){
        if(obj->val[row][i]!=x){
            win =false;
            break;
        }
    }
    if(win)
        return x;
    win=true;
    //x=obj->val[0][col];
    if(x!=0)
    for(int i=0;i<n;i++){
        if(obj->val[i][col]!=x){
            win =false;
            break;
        }
    }
    if(win)
        return x; 
    win=true;
   // x=obj->val[0][0];
    if(x!=0)
    for(int i=0;i<n;i++){
        if(obj->val[i][i]!=x){
            win=false;
            break;
        }

    } 
    if (win) return x;
    win=true;
      // Check anti-diagonal (top-right to bottom-left)
    //x = obj->val[0][n - 1];
    for (int i = 0; i < n; i++) {
        if (obj->val[i][n - 1 - i] != x) {
            win = false;
            break;
        }
    }
    
    if(win)
        return x;
    else
        return 0;

}
int ticTacToeMove(TicTacToe* obj, int row, int col, int player) {
    obj->val[row][col]=player;
    return check(obj,row,col,obj->size);
}
void ticTacToeFree(TicTacToe* obj) {
      for(int i = 0; i < obj->size; i++)
        free(obj->val[i]);
    free(obj->val);
    free(obj);
}

/**
 * Your TicTacToe struct will be instantiated and called as such:
 * TicTacToe* obj = ticTacToeCreate(n);
 * int param_1 = ticTacToeMove(obj, row, col, player);
 
 * ticTacToeFree(obj);
*/
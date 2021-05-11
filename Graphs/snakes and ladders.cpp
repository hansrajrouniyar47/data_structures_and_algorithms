class Solution {
     /* the simpler approach is that we try to do bfs and store the count of moves that is 
 taken to climb ladder or fall snakes actually and the rest is simple bfs
 
 
 
 */
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q; //BFS
        unordered_map<int, int> moves;
        moves[1]=0; //no moves when we are in square 1
        q.push(1);
        while (!q.empty())
        {
            int curr_sq=q.front(); // current square (val from 1..n*n)
            q.pop();
            
            // try all the next 6 pos but not over n*n
            for(int i=1; i <= 6;++i)
            {
                int next_sq=curr_sq+i; // next pos when we move from sq
                
                 if (next_sq > n*n)
                    break;
                
                // Determine the next sq val, on snake or ladder
                // Compute row and col in the board
                int row = (next_sq-1)/n; 
                // the colum depends on if row is even or odd
                int col = (row % 2 ==0) ? (next_sq-1) % n : n-1 - (next_sq-1) % n;
                
                // the next sq can be on the snake (-1) or ladder
                if(board[n-1-row][col] != -1)
                    next_sq= board[n-1-row][col];
                    
                // update the moves for that square               
                if (moves.count(next_sq)==0)
                {
                    moves[next_sq]=moves[curr_sq] + 1; // moves to sq plus 1
                    if(next_sq==n*n) return moves[next_sq]; // early exit
                    q.push(next_sq);
                }
            }
             
        }
        
        return -1;
    }
};
// nQueen and Sudoku Solver
#include <bits/stdc++.h>
using namespace std;

class NQueen
{
public:
    /*
// Filling the queen row by row
bool isSafe(int row, int col, int n, vector<vector<char>> &board)
{

    // . . Q . 00 01 02 03
    // . . . . 10 11 12 13
    // . . . . 20 21 22 23
    // . . . . 30 31 32 33
for (int i = row; i >= 0; i--)
{
    if (board[i][col] == 'Q')
        return false;
}

int nrow = row;
int ncol = col;

while (nrow >= 0 && ncol >= 0)
{
    if (board[nrow][ncol] == 'Q')
        return false;
    nrow--;
    ncol--;
}

nrow = row;
ncol = col;
while (nrow >= 0 && ncol <= n)
{
    if (board[nrow][ncol] == 'Q')
        return false;
    nrow--;
    ncol++;
}
return true;
}
*/

    // Filling the queen column wise

    bool isSafe(int row, int col, int n, vector<vector<char>> &board)
    {

        // . . Q . 00 01 02 03
        // . . . . 10 11 12 13
        // . . . . 20 21 22 23
        // . . . . 30 31 32 33

        for (int i = col; i >= 0; i--)
        {
            if (board[row][i] == 'Q')
                return false;
        }

        int nrow = row;
        int ncol = col;

        while (nrow >= 0 && ncol >= 0)
        {
            if (board[nrow][ncol] == 'Q')
                return false;
            nrow--;
            ncol--;
        }

        nrow = row;
        ncol = col;
        while (nrow < n && ncol >= 0)
        {
            if (board[nrow][ncol] == 'Q')
                return false;
            nrow++;
            ncol--;
        }
        return true;
    }

    void solve(int col, int n, vector<vector<char>> &board, map<int, char> &upperDiagonal, map<int, char> &leftRows, map<int, char> &lowerDiagonal)
    {
        if (col == n)
        {
            // print the solution
            for (auto &x : board)
            {
                for (auto &y : x)
                {
                    cout << y << " ";
                }
                cout << endl;
            }

            return;
        }

        for (int row = 0; row < n; row++)
        {
            if ((upperDiagonal[(n - 1) + (col - row)] == '.') && (leftRows[row] == '.') && (lowerDiagonal[(row + col)] == '.'))
            {
                board[row][col] = 'Q';
                upperDiagonal[n - 1 + col - row] = 'Q';
                leftRows[row] = 'Q';
                lowerDiagonal[row + col] = 'Q';

                solve(col + 1, n, board, upperDiagonal, leftRows, lowerDiagonal);
                upperDiagonal[n - 1 + col - row] = '.';
                leftRows[row] = '.';
                lowerDiagonal[row + col] = '.';
                board[row][col] = '.';
            }
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        int n;
        cin >> n;
        vector<vector<char>> board(n, vector<char>(n, '.'));

        map<int, char> upperDiagonal, lowerDiagonal, leftRows;
        for (int i = 0; i <= ((2 * n) - 1); i++)
        {
            upperDiagonal[i] = '.';
            lowerDiagonal[i] = '.';
        }

        // for (int i = 0; i <= ((2 * n )- 1); i++)
        // {
        //     cout << upperDiagonal[i] <<" "<<endl;
        //     cout << lowerDiagonal[i] <<" "<<endl;
        // }

        for (int i = 0; i < n; i++)
            leftRows[i] = '.';

        solve(0, n, board, upperDiagonal, leftRows, lowerDiagonal);

        return 0;
    }
};

class Sudoku
{
public:
    // Using 2 for loops
    bool isSafe(int row, int col, int k, int n, vector<vector<int>> &sudoku)
    {
        for (int i = 0; i < n; i++)
        {
            if (sudoku[row][i] == k)
                return false;
            if (sudoku[i][col] == k)
                return false;
            if (sudoku[(3 * (row / 3)) + (i / 3)][(3 * (col / 3)) + (i % 3)] == k)
                return false;
        }
        return true;
    }

    bool solveSudoku(int n, vector<vector<int>> &sudoku)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == n - 1 && j == n - 1)
                {
                    for (auto &x : sudoku)
                    {
                        for (auto &y : x)
                            cout << y << " ";
                        cout << endl;
                    }
                }

                if (sudoku[i][j] == 0)
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (isSafe(i, j, k, n, sudoku))
                        {
                            sudoku[i][j] = k;
                            if (solveSudoku(n, sudoku))
                            {
                                return true;
                            }
                            sudoku[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    // Using Hashing
    bool utilFunc(int r, int c, int n, vector<vector<int>> &sudoku, vector<map<int, int>> &row, vector<map<int, int>> &col, map<pair<int, int>, map<int, int>> &mp)
    {
        if (r == 9)
            return true;

        if (c == 9)
        {
            if (utilFunc(r + 1, 0, n, sudoku, row, col, mp))
            {
                return true;
            }
        }

        if (sudoku[r][c] != 0)
        {
            if (utilFunc(r, c + 1, n, sudoku, row, col, mp))
            {
                return true;
            }
        }
        else
        {
            int nrow = r / 3, ncol = c / 3;
            for (int i = 1; i <= 9; i++)
            {
                if (row[r][i] == 0 && col[c][i] == 0 && mp[{nrow, ncol}][i] == 0)
                {
                    sudoku[r][c] = i;
                    row[r][i] = 1;
                    col[c][i] = 1;
                    mp[{nrow, ncol}][i] = 1;
                    if (utilFunc(r, c + 1, n, sudoku, row, col, mp))
                    {
                        return true;
                    }
                    sudoku[r][c] = 0;
                    row[r][i] = 0;
                    col[c][i] = 0;
                    mp[{nrow, ncol}][i] = 0;
                }
            }
        }
        return false;
    }

    void solve(int n, vector<vector<int>> &sudoku, vector<map<int, int>> &row, vector<map<int, int>> &col, map<pair<int, int>, map<int, int>> &mp)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sudoku[i][j] != 0)
                {
                    row[i][sudoku[i][j]] = 1;
                    col[j][sudoku[i][j]] = 1;
                    mp[{i / 3, j / 3}][sudoku[i][j]] = 1;
                }
            }
        }

        if (utilFunc(0, 0, n, sudoku, row, col, mp))
        {
            for (auto &x : sudoku)
            {
                for (auto &y : x)
                {
                    cout << y << " ";
                }
                cout << endl;
            }
        }
    }

    int
    main()
    {
        vector<vector<int>> sudoku = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};

        vector<map<int, int>> row(9), col(9);
        map<pair<int, int>, map<int, int>> mp;

        solve(9, sudoku, row, col, mp);

        return 0;
    }
};

class NColouringProblem
{
    bool CanBeColoured(int node, int n, int **graph, int col, int *color)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != node && graph[i][node] == 1 && color[i] == col)
            {
                return false;
            }
        }
        return true;
    }

    bool colourGraph(int node, int **graph, int n, int m, int *color)
    {
        if (node == n)
        {
            return true;
        }

        for (int i = 1; i <= m; i++)
        {
            if (CanBeColoured(node, n, graph, i, color))
            {
                color[node] = i;
                if (colourGraph(node + 1, graph, n, m, color))
                {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }

    int main()
    {
        int vertex, edges;
        cin >> vertex >> edges;

        int color[vertex] = {0};

        int **graph = new int *[vertex];

        for (int i = 0; i < vertex; i++)
        {
            graph[i] = new int[vertex];
            memset(graph[i], 0, vertex * sizeof(graph[0]));
        }

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        int m;
        cin >> m;

        if (colourGraph(0, graph, vertex, m, color))
        {
            cout << "Can Be Coloured!!!" << endl;
        }
        else
        {
            cout << "Cannot be Coloured!!!" << endl;
        }

        for (int i = 0; i < vertex; i++)
        {
            delete[] graph[i];
        }
        delete[] graph;

        return 0;
    }
};

class Pallindrome
{

    bool isPallindrome(string s, int start, int end)
    {
        if (start >= end)
        {
            return true;
        }

        if (s[start] != s[end])
            return false;

        return isPallindrome(s, start + 1, end - 1);
    }

    void PallindromePartitioning(int idx, string s, vector<string> &sol)
    {
        if (idx == s.length())
        {
            for (auto &x : sol)
            {
                cout << x << " ";
            }
            cout << endl;
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (isPallindrome(s, idx, i))
            {
                sol.push_back(s.substr(idx, i - idx + 1));
                PallindromePartitioning(i + 1, s, sol);
                sol.pop_back();
            }
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        vector<string> sol;
        PallindromePartitioning(0, "aabb", sol);
        return 0;
    }
};

class Kpermutation
{
    void KthPermutation(vector<int> &arr, int n, int k)
    {
        int fact = 1;
        vector<int> sol;
        sol.push_back(arr[0]);

        for (int i = 1; i < n; i++)
        {
            fact *= i;
            sol.push_back(arr[i]);
        }
        // cout << fact <<endl;

        while (true)
        {
            cout << sol[k / fact];
            sol.erase(sol.begin() + (k / fact));
            k = k % fact;
            if (sol.size() == 0)
                break;
            fact = fact / sol.size();
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        KthPermutation(arr, n, k - 1);

        return 0;
    }
};

bool isSafe(int row, int col, vector<vector<int>> &arr)
{
    if ((row >= 0 && row < 8) && (col >= 0 && col < 8) && (arr[row][col] == -1))
    {
        return true;
    }
    return false;
}

bool KnightProblem(int row, int col, int moves, int n, vector<vector<int>> &arr, vector<int> &xaxis, vector<int> &yaxis)
{
    
    if (moves == 64)
    {
        for (auto &x : arr)
        {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
        return true;
    }

    for (int i = 0; i < 8; i++)
    {
        int newx = row + xaxis[i];
        int newy = col + yaxis[i];

        if (isSafe(newx, newy, arr))
        {
            arr[newx][newy] = moves;
            if (KnightProblem(newx, newy, moves + 1, n, arr, xaxis, yaxis))
            {
                return true;
            }
            else
            {
                arr[newx][newy] = -1;
            }
        }
    }
    return false;
}

int main()
{
    int n = 8;
    vector<vector<int>> arr(n, vector<int>(n, -1));
    vector<int> xaxis = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> yaxis = {1, 2, 2, 1, -1, -2, -2, -1};
    int moves = 0;

    arr[0][0] = 0;

    cout << KnightProblem(0, 0, 1, n, arr, xaxis, yaxis);

    return 0;
}

/*
bool isSafe(int row, int col, vector<vector<int>> &board)
{
    int num = 8;
    if ((row >= 0 && row < num) && (col >= 0 && col < num) && board[row][col] == -1)
    {
        return true;
    }
    return false;
}

int knightProblem(int row, int col, int index, vector<int> &rows, vector<int> &cols, vector<vector<int>> &board)
{
    if (index == 64)
    {
        for (auto &x : board)
        {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
        return 1;
    }

    for (int i = 0; i < 8; i++)
    {
        int newx = row + rows[i];
        int newy = col + cols[i];
        if (isSafe(newx, newy, board))
        {
            board[newx][newy] = index;
            if(knightProblem(newx, newy, index + 1, rows, cols, board) == 1){
                return 1;
            }
        }
        else
        {
            board[newx][newy] = -1;
        }
    }
    return 0;
}
int main()
{
    int n = 8;
    vector<vector<int>> arr(n, vector<int>(n, -1));
    vector<int> xaxis = {2, 1, -1, -2, -2, -1, 2, 1};
    vector<int> yaxis = {1, 2, 2, 1, -1, -2, -1, -2};

    arr[0][0] = 0;

    // knightProblem(arr, n, 1, 0, 0, xaxis, yaxis);
   cout << knightProblem(0, 0, 1, xaxis, yaxis, arr);

    return 0;
}

void knightProblem(vector<vector<int>> &arr, int n, int moves, int row, int col, vector<int> &xaxis, vector<int> &yaxis)
{
    if (moves == 63)
    {
        for (auto &x : arr)
        {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        int newx = row + xaxis[i];
        int newy = col + yaxis[i];

        if (isSafe(newx, newy, arr))
        {
            arr[newx][newy] = moves;
            knightProblem(arr, n, moves + 1, newx, newy, xaxis, yaxis);
        }
        else
        {
            arr[newx][newy] = -1;
        }
    }
}

int main()
{
    int n = 8;
    vector<int> xaxis = {2, 1, -1, -2, -2, -1, 2, 1};
    vector<int> yaxis = {1, 2, 2, 1, -1, -2, -1, -2};

    vector<vector<int>> arr(n, vector<int>(n, -1));
    arr[0][0] = 0;

    knightProblem(arr, n, 1, 0, 0, xaxis, yaxis);

    return 0;
}
*/

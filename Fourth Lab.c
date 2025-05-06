// Symmetric Tree //
static bool isMirror(struct TreeNode *left, struct TreeNode *right) {
    if (left == NULL && right == NULL) {
        return true;            
    }
    if (left == NULL || right == NULL) {
        return false;           
    }

    return (left->val == right->val) &&
           isMirror(left->left,  right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root) {
    if (root == NULL) {
        return true;    
    }
    return isMirror(root->left, root->right);
}

//Number of Islands //
static void flood(char **grid, int m, int n, int row, int col) {
    
    int   stack_sz = m * n;
    int  *stack_r  = (int *)malloc(sizeof(int) * stack_sz);
    int  *stack_c  = (int *)malloc(sizeof(int) * stack_sz);
    int   top      = 0;

    stack_r[top] = row;
    stack_c[top] = col;

    while (top >= 0) {
        int r = stack_r[top];
        int c = stack_c[top--];

        
        if (grid[r][c] == '0') {
            continue;
        }

        grid[r][c] = '0';  

        
        if (r > 0 && grid[r - 1][c] == '1') {
            stack_r[++top] = r - 1;
            stack_c[top]   = c;
        }
        if (r + 1 < m && grid[r + 1][c] == '1') {
            stack_r[++top] = r + 1;
            stack_c[top]   = c;
        }
        if (c > 0 && grid[r][c - 1] == '1') {
            stack_r[++top] = r;
            stack_c[top]   = c - 1;
        }
        if (c + 1 < n && grid[r][c + 1] == '1') {
            stack_r[++top] = r;
            stack_c[top]   = c + 1;
        }
    }

    free(stack_r);
    free(stack_c);
}


int numIslands(char **grid, int gridSize, int *gridColSize) {
    if (grid == NULL || gridSize == 0 || gridColSize == NULL || gridColSize[0] == 0) {
        return 0;
    }

    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == '1') {
                ++count;
                flood(grid, m, n, r, c);
            }
        }
    }

    return count;
}

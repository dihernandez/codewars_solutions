void printLCSubStr(char* X, char* Y, int m, int n) 
{ 
    // Create a table to store lengths of longest common 
    // suffixes of substrings.   Note that LCSuff[i][j] 
    // contains length of longest common suffix of X[0..i-1] 
    // and Y[0..j-1]. The first row and first column entries 
    // have no logical meaning, they are used only for 
    // simplicity of program 
    int LCSuff[m + 1][n + 1]; 
  
    // To store length of the longest common substring 
    int len = 0; 
  
    // To store the index of the cell which contains the 
    // maximum value. This cell's index helps in building 
    // up the longest common substring from right to left. 
    int row, col; 
  
    /* Following steps build LCSuff[m+1][n+1] in bottom 
       up fashion. */
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                LCSuff[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) { 
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1; 
                if (len < LCSuff[i][j]) { 
                    len = LCSuff[i][j]; 
                    row = i; 
                    col = j; 
                } 
            } 
            else
                LCSuff[i][j] = 0; 
        } 
    } 
  
    // if true, then no common substring exists 
    if (len == 0) { 
        cout << "No Common Substring"; 
        return; 
    } 
  
    // allocate space for the longest common substring 
    char* resultStr = (char*)malloc((len + 1) * sizeof(char)); 
  
    // traverse up diagonally form the (row, col) cell 
    // until LCSuff[row][col] != 0 
    while (LCSuff[row][col] != 0) { 
        resultStr[--len] = X[row - 1]; // or Y[col-1] 
  
        // move diagonally up to previous cell 
        row--; 
        col--; 
    } 
  
    // required longest common substring 
    cout << resultStr; 
} 
  
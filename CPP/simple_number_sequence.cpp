#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

//int longestCommonSubstring(int s1_len, int s2_len, int count){
    // int LCSmatrix[s1.length() + 1][s2.length() + 1];
    // int result = 0;
    
    // for(int i = 0; i <= s1.length(); i++) {
    //     for(int j = 0; j < s2.length(); j++) {
    //         if(i == 0 || j==0) {
    //             LCSmatrix[i][j] = 0;
    //         }
    //         else if(s1[i-1] == s2[j-1]) {
    //             LCSmatrix[i][j] = LCSmatrix[i-1][j-1] + 1;
    //             result = max(result, LCSmatrix[i][j]);
    //         }
    //     }
    // }
    // return result;

//}
int printLCSubStr(string X, string Y, int m, int n) 
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
        return 0; 
    } 
  
    return len;
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
  


// int lcs(int i, int j, int count) {
//     if (i == 0 || j == 0) 
//         return count; 
          
//     if (s1[i-1] == s2[j-1]) { 
//         count = lcs(i - 1, j - 1, count + 1); 
//     } 
//         count = max(count, max(lcs( i, j - 1, 0), lcs( i - 1, j, 0))); 
//     cout << "count is " << count << endl;
//     return count;
// }

int findOrderBeta(string s) {

    int step_size = 1;
    int count = 1;
    stringstream left;
    stringstream right;
    string l = "",r = "";

    while (step_size < s.length()/2 + 1)
    {
        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j < step_size; j++){
                l += s[j];
            }
            cout << " after for loop left is " << l << " step_size is " << step_size << endl;

            for(int j = step_size; j < step_size*2; j++) {
                r += s[j];
            }
            cout << " after for loop right is " << r << " step_size is " << step_size << endl;

            // while(left >> l && right >> r) {
            // }
            
            count = max(count, printLCSubStr(l, r, l.length(), r.length()));
            cout << "lcs is " << printLCSubStr(l, r, l.length(), r.length()) << endl;
            l = "";
            r = "";

            //cout << "left is " << left.str() << " right is " << right.str() << " step size is " << step_size << endl;

        }
        step_size++;
    }

    return count;
    

}

long findOrder(string s) {
    int order = 1;
    //for (int i = 1; i < s.length()- order; i++) {
        // if(s[i - 1] == s[i]) {
        //     order++;
        // }
       // if (s.substr(i - order - 1, i - 1) == s.substr(i - order,i) ){
            // cout << "order is " << order << " substr for covered is " << atoi(s.substr(i,i + order).c_str())  << " and for future is " << atoi(s.substr(i - order, i).c_str()) << endl;
            // if(atoi(s.substr(i,i + order).c_str()) - atoi(s.substr(i - order, i).c_str()) != 0){
            //     order++;
            // } else if(atoi(s.substr(i,i + order).c_str()) - atoi(s.substr(i - order, i).c_str()) >= 1) {
            //     break;
            // }
       // }
        
    //}

    stringstream left;
    stringstream right;
    string l,r;
    cout << "s is " << s << endl;
    
    for(int i = 0; i < s.length()/2; i++) {
        left << s[i];

        cout << "left is " << left.str() << endl;


        l = left.str();

        if(l != r){
            order++;
            //cout << "left doesn't equal right, order is " << order;
        }
    }

    for(int i = s.length(); i > s.length()/2; i--) {
        right << s[i + 1];
        r = right.str();
        cout << "right is " << r << endl;
    }


    //cout << " left is " << l << endl;
    //cout << "right is " << r << endl;


    // while(s.length() > 0) {
    //     string::iterator it = s.begin() + 1;
    //     if(*(it -1) == *it) {
    //         order++;
    //     }
    //     cout << "before erase " << endl;
    //     s.erase(s.begin());
    //     it++;

    // }
    string s1 = left.str(), s2 = right.str();
    int n, m;
    n = s1.size();
    m = s2.size();
    cout << "here " << endl;
    cout << "longest common subtsr is " << printLCSubStr(s1, s2, m, n) << endl;
    int substr_size = printLCSubStr(s1, s2, m, n) + 1;
    return substr_size;
}

int missing(string s) {
    return 0;
}

int main() {

int missing_int = missing("123567");
//long order = findOrder("99991000110002");
int orderbeta = findOrderBeta("99991000110002");
cout << missing_int << endl;
cout << "order is " << orderbeta << endl;;
return 0;
}
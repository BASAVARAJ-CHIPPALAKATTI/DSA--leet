class Solution {
public:
    // Helper function: Count number of subarrays with all 1s in a 1D array
    // Example: vec = [1,1,0,1] → 
    // subarrays of 1s are [1], [1,1], [1], so result = 3
    int findrect(vector<int>& vec) {
        int curr = 0; // length of current consecutive streak of 1s
        int res = 0;  // total count of subarrays of 1s
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == 0) {
                curr = 0; // streak broken
            } else {
                curr++;   // streak continues
            }
            res += curr; // add all subarrays ending at this position
        }
        return res;
    }

    // Main function: Count submatrices with all 1s
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();       // number of rows
        int n = mat[0].size();    // number of columns
        int res = 0;              // final result

        // Choose starting row of the submatrix
        for(int startrow = 0; startrow < m; startrow++) {

            // Initialize colvec with all 1s (size = number of columns)
            // colvec[j] will tell whether column j is full of 1s
            // between rows [startrow ... endrow]
            vector<int> colvec(n, 1);

            // Choose ending row of the submatrix
            for(int endrow = startrow; endrow < m; endrow++) {

                // Update colvec: AND operation ensures that
                // colvec[j] = 1 only if every cell from startrow to endrow
                // in column j is 1
                for(int col = 0; col < n; col++) {
                    colvec[col] = colvec[col] & mat[endrow][col];
                }

                // Now colvec is a compressed "row" that shows
                // which columns form continuous bands of 1s
                // → count subarrays of 1s in colvec
                res += findrect(colvec);
            }
        }
        return res;
    }
};

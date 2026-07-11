class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        int w = matrix[0].size();

        int start = 0, end = h * w - 1;
        cout << "h = " << h << " w = " << w << endl;

        while(start <= end){
            int mid = (start + end) / 2;
            int mid_row = mid / w;
            int mid_col = mid % w;
            int mid_val = matrix[mid_row][mid_col];
            if(mid_val == target) return true;
            else if (target < mid_val) {
                end = mid - 1;
            } else start = mid + 1;
        }
        return false;
    }
};

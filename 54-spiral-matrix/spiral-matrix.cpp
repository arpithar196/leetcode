class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        vector<int> res;
        while(top<=bottom && left <= right){
            //1->2->3
            for(int i=left;i<=right;i++)
                res.push_back(matrix[top][i]);
            top++;  
            //6->9
            for(int i=top;i<=bottom;i++)
                res.push_back(matrix[i][right]);
            right--;
             if (top <= bottom) {
            //8->7
            for(int i=right;i>=left;i--)
                res.push_back(matrix[bottom][i]);
            bottom--;
             }
             if (left <= right) {
            //4
            for(int i=bottom;i>=top;i--)
                res.push_back(matrix[i][left]);
            left++;
             }
            
        }
        return res;

        //}
        //return res;
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        queue<pair<pair<int,int>, int>> q;
        q.push({{sr,sc},color});
        int delrow[]={-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int color = q.front().second;
            ans[r][c]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol =  c + delcol[i];
                if(nrow < row && nrow >=0 && ncol < col && ncol >= 0 && image[nrow][ncol] == inicolor 
                && ans[nrow][ncol] != color ){
                    q.push({{nrow,ncol},color});
                }  
            }
        }
        return ans;
    }
};
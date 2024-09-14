class Solution {

    private:
    void dfs(int row,int col,int inicolor,vector<vector<int>> &image,vector<vector<int>> &ans,int delrow[]
    ,int delcol[],int color,int sr,int sc){
        ans[sr][sc] = color;
        for(int i=0;i<4;i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if( nrow < row && nrow >= 0 && ncol < col && ncol >= 0 && image[nrow][ncol] == inicolor
             && ans[nrow][ncol] != color){
                dfs(row,col,inicolor,image,ans,delrow,delcol,color,nrow,ncol);
             }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        int delrow[]={-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        dfs(row,col,inicolor,image,ans,delrow,delcol,color,sr,sc);
        return ans;
    }
};
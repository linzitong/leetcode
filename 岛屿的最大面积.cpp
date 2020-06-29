//https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1034/
//给定一个包含了一些 0 和 1 的非空二维数组 grid 。
//一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
//找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
//思路：使用在线等价类，遍历整个grid，如果当前节点为1且上面或者左面有非0节点，那么合并这两个类

class Solution {
public:
    int find1(int e,int p[]){
        while(p[e]!=e){
            e=p[e];
        }
        return e;
    }

    void union1(int i,int j,int p[],int num[]){
        if(i!=j){
            p[i]=j;
            num[j]=num[j]+num[i];
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int p[m*n];
        int num[m*n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                p[n*i+j]=n*i+j;
                if(grid[i][j]==1){
                    num[n*i+j]=1;
                }else{
                    num[n*i+j]=0;
                }
            }
        }

        for(int j=0;j<n-1;j++){
            if(grid[0][j]>0&&grid[0][j+1]>0){
                union1(j,j+1,p,num);
            }
        }
        for(int i=1;i<m;i++){
            int j=0;
            if(grid[i][j]>0&&grid[i-1][j]>0){
                union1(find1(n*i+j,p),find1(n*i-n+j,p),p,num);
            }
            for(int j=1;j<n;j++){
                if(grid[i][j]>0&&grid[i][j-1]>0){
                    union1(find1(n*i+j,p),find1(n*i+j-1,p),p,num);
                }
                if(grid[i][j]>0&&grid[i-1][j]>0){
                    union1(find1(n*i+j,p),find1(n*i-n+j,p),p,num);
                }
            }
        }
        int max=0;
        for(int i=0;i<m*n;i++){
            if(num[i]>max){
                max=num[i];
            }
        }

        //for(int i=0;i<m*n;i++){
        //	cout<<num[i]<<' ';
        //}
        //cout<<endl;
        //for(int i=0;i<m*n;i++){
        //	cout<<p[i]<<' ';
        //}
        //cout<<endl;
        return max;	
    }
};

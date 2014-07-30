/*
 * The idea could be using stack structure, which need extra storage space,
 * Recursion --> DP top down --> DP bottom up. 
 */

#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

class Solution{
	public:
		int uniquePaths(int m, int n) {
			int ans = 0;
			int path[100][100];
			int i, j; 

			for(i = 0 ; i < 100; i++)
				for(j = 0; j < 100; j++)
					if(i && j)
						path[i][j] = 0;
					else
						path[i][j] = 1;
			
			for(i = 1; i < m; i++)
				for(j = 1; j < n; j++)
						path[i][j] = path[i-1][j] + path[i][j-1];

			return path[m - 1][n - 1];
		}		

};

int main(void){

	/*
	int numofP = 3;
	Solution *sol;
	sol = new Solution();
	vector<string> result = sol->GenerateParenthesis(numofP);
	int i = 0;	

	// Very strange c++ template, we need to declare all the parameter in the same type in the vector name space
	for(vector<string>::iterator it = result.begin(); it != result.end(); ++it){
		i ++;
		cout <<"Pairs " << i << ": " << *it <<endl;
	}
	*/

	int col = 7, row = 3;
	Solution *sol = NULL;
	sol = new Solution();
	int result = sol->uniquePaths(col, row);
	cout <<"unique paths :"<< result <<endl;
	return 0;
}

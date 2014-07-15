/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

/*
 * The idea could be using stack structure, which need extra storage space,
 */

#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

class Solution{
	public:
		void recursion(int left, int right, vector<string>& vector, string s){
		}

		vector<string> GenerateParenthesis(int n){
			vector<string> tmpv;
			if(n <= 0) return tmpv = "";
			if(n == 1) return tmpv = "()";
			recursion(n, n, tmpv, "");
			return result;
		}
}

int main(void){

	int numofP = 3;
	vector<string> result = Generate
	for( vector<string>::iterator it = GenerateParenthesis(numofP).begin()

	return 0;
}

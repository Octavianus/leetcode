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
		void recursion(int left,
			       int right, 
			       vector<string>& vector, 
			       string s){
			if(left > right)
				return;
			if(left){
				recursion(left - 1, right, vector, s + "(");	
			}
			if(right){
				recursion(left, right - 1, vector, s + ")");
			}

			if(!(left || right))
				vector.push_back(s);
		}

		vector<string> GenerateParenthesis(int n){
			vector<string> tmpv;
			if(n <= 0) return vector<string>(1,"");
			if(n == 1) return vector<string>(1,"()");
			recursion(n, n, tmpv, "");
			return tmpv;
		}
};

int main(void){

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

	return 0;
}

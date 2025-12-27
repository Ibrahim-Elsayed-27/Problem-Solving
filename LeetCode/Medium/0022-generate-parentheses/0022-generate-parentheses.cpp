class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string combination;
        generateParenthesisDFS(result, combination, n, n);
        return result;
    }

    void generateParenthesisDFS(vector<string>& result, string combination, int open_count, int close_count){
        if(!open_count && !close_count){
             result.push_back(combination);
             return;
        }
        if(open_count){
            char open = '(';
            string temp1 = combination;
            temp1+=open;
            generateParenthesisDFS(result, temp1, open_count-1, close_count);
        }
        
        if(close_count > open_count){
            char close = ')';
            string temp2 = combination;
            temp2+= close;
            generateParenthesisDFS(result, temp2, open_count, close_count-1);
        }

        return;

    }
};

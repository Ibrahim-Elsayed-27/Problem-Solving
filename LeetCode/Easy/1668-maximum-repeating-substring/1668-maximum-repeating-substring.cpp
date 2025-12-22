class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int max_count = 0;
        int count = 0;
        for(int k=0; k<sequence.size();++k){
            for(int i=k; i<sequence.size(); ++i){
                bool flag = true;
                for(int j=0; j<word.size(); ++j){
                    if(sequence[i+j] != word[j]){
                        count = 0;
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ++count;
                    max_count = (max_count< count? count: max_count);
                    i+= word.size()-1;
                }

            }

            count = 0;
        }

        return max_count;
    }

};
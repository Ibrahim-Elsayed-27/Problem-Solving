class Solution {
public:
    int strStr(string haystack, string needle) {
        int potential_start = -1;
        for(int i=0; i<haystack.size() ; ++i){
            if(haystack[i] == needle[0]){
                potential_start = i;
                int k = i;
                int match = true;
                for(int j=0; j<needle.size(); ++j){
                    if(k >= haystack.size()){
                        match = false;
                        break;
                    }
                    if(needle[j] != haystack[k]){
                        match =false;
                    }
                    ++k;
                }

                if(match){
                    break;
                }else{
                    potential_start = -1;
                }
            }
        }

        return potential_start;

    }
};
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int cits_size = citations.size();
        vector<int> inc_cit(cits_size+1, 0);
        for(int cit: citations){
            if(cit >= cits_size){
                inc_cit[cits_size]++;
            }else{
                inc_cit[cit]++;
            }
        }
        int papers = 0;
        for(int i= cits_size; i>=0; --i){
            papers += inc_cit[i];
            if(papers >= i){
                return i;
            }
        }

        return 1;
    }
};
int maxProfit(int* prices, int pricesSize) {
    int min=*prices,current=0,count=0;
    
    for(int i=1;i<pricesSize;i++){
        if(*(prices+i) <= min && current == 0){
            min = *(prices+i);
        }else{
            if(*(prices+i) > current){
                current = *(prices+i);
                if (i==pricesSize-1){
                    count += (current - min);
                }
            }else{
                count += (current - min);
                current=0;
                min=*(prices+i);
            }
            
        }
        
    }
    return count;
}
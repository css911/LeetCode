class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> first;
        queue<int> second;
        
        char firstChar = senate[0];
        char secondChar;
        
        for(int i = 0; i< senate.size(); i++ ){
            if(firstChar!=senate[i]){
                secondChar = senate[i];
                break;
            }
        }
        
        for(int i = 0; i<senate.size();i++ ){
            if(firstChar==senate[i]){
                first.push(i);
            }
            if(secondChar==senate[i]){
                second.push(i);
            }
            
        }
        
        while(!first.empty() && !second.empty()){
            int temp1 = first.front();
            int temp2 = second.front();
            
            if(temp1<temp2){
                first.pop();
                first.push(temp1+senate.size()+senate.size());
                second.pop();
            }
            if(temp1>=temp2){
                second.pop();
                second.push(temp2 + senate.size()+senate.size());
                first.pop();
            }
            
          }
        string resultant;
        if(!first.empty() && second.empty()){
            if(firstChar =='R'){
               resultant = "Radiant"; 
                
            }
            if(firstChar == 'D'){
                resultant = "Dire";
                
            }
        }
        
        if(!second.empty() && first.empty()){
            if(secondChar == 'R'){
                resultant = "Radiant";
            }
            if(secondChar == 'D'){
                resultant = "Dire";
            }
        }
        
        return resultant;    
    }
};

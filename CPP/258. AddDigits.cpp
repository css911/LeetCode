class Solution {
public:
    int addDigits(int num) {
         string numString = to_string(num);
        while(numString.size()!=1){
            int temp = 0;
            for(int i = 0;i<numString.size();i++){
                temp = temp+(int)numString[i]-'0';
            }
            numString = to_string(temp);
        }
    return stoi(numString);
    
    }
};

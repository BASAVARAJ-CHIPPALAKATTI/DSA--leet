class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low ;i<=high;i++){
            if(i > 10 && i < 100 && i % 11 == 0){
                count++;
            }
            if(i>1000 && i <=9999){
                int forth=i%10;

                int temp=i/10;
                int third=temp%10;

                temp=temp/10;
                int sec=temp%10;

                temp=temp/10;
                int first=temp%10;

                if((first+sec)==(third+forth)){
                    count++;
                }
            }
        }
        return count;
    }
};
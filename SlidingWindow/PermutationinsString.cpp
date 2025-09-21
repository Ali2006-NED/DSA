#include<string>
#include<iostream>
using namespace std;
class Solution {
private:
bool checkEqual(int count1[],int count2[]){
    for(int i = 0; i < 26; i++){
        if(count1[i] != count2[i]) return 0;
    }
    return 1;
}
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};
        while(i < windowSize){
            int index = s1[i] - 'a';
            count1[index]++;
            i++;
        }
        i = 0;
        while(i < windowSize && i < s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        if(checkEqual(count1,count2)) return 1;
        
        
        while(i < s2.length()){
            int newindex = s2[i] - 'a';
            count2[newindex]++;
            int oldchar = s2[i-windowSize] - 'a';
            count2[oldchar]--;
            i++;
            if(checkEqual(count1,count2)) return 1;
        }
        return 0;
    }
};
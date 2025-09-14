#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> decrypt(vector<int>& code, int k) {
        vector<int> decryptedCode(code.size(),0);
        if(k == 0) return decryptedCode;
        int start = 1;
        int end = k;
        int sum = 0;
        if(k < 0){
            start = code.size() - abs(k);
            end = code.size() - 1;
        }
        for(int i = start; i <= end; i++){
            sum+=code[i];
        }

        for(int i = 0; i < code.size(); i++){
            decryptedCode[i] = sum;
            sum -= code[start % code.size()];
            sum += code[(end + 1) % code.size()];
            start++;
            end++;

        }
        return decryptedCode;

    }
int main() {
    vector<int> code = {5,7,1,4};
    int k = 3;
    vector<int> result = decrypt(code, k);
    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}
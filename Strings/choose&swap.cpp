#define MAX 26
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    // string chooseandswap(string str) {
    //     // Code Here
    //     string beststr = str;
        
    //     set<char> unique_chars_set;
    //     for (char ch : str) {
    //         unique_chars_set.insert(ch);
    //     }
    //     // Convert the set to a vector to iterate with indices.
    //     vector<char> chars_in_str(unique_chars_set.begin(), unique_chars_set.end());

    //     for(int i = 0; i < chars_in_str.size() ; i++) {
    //         for(int  j = i+1 ; j < chars_in_str.size(); j++) {
    //             char char1 = chars_in_str[i];
    //             char char2 = chars_in_str[j];
    //             string temp_str = str;
    //             for (int k = 0; k < temp_str.length(); ++k) {
    //                 if (temp_str[k] == char1) {
    //                     temp_str[k] = char2;
    //                 } else if (temp_str[k] == char2) {
    //                     temp_str[k] = char1;
    //                 }
    //             }
                
    //             if(temp_str < beststr) beststr = temp_str; 
    //         }
    //     }
        
    //     return beststr;
    // }
    string chooseandswap(string str) {
            int i, j;
            // To store the first index of
            // every character of str
            int chk[MAX];
            for (i = 0; i < MAX; i++)
                chk[i] = -1;
            int n = str.length();
            // Store the first occurring
            // index every character
            for (i = 0; i < n; i++) {
          
                // If current character is appearing
                // for the first time in str
                if (chk[str[i] - 'a'] == -1)
                    chk[str[i] - 'a'] = i;
            }
          
            // Starting from the leftmost character
            for (i = 0; i < n; i++) {
          
                bool flag = false;
          
                // For every character smaller than str[i]
                for (j = 0; j < str[i] - 'a'; j++) {
          
                    // If there is a character in str which is
                    // smaller than str[i] and appears after it
                    if (chk[j] > chk[str[i] - 'a']) {
                        flag = true;
                        break;
                    }
                }
          
                // If the required character pair is found
                if (flag)
                    break;
            }
          
            // If swapping is possible
            if (i < n-1) {
          
                // Characters to be swapped
                char ch1 = str[i];
                char ch2 = char(j + 'a');
          
                // For every character
                for (i = 0; i < n; i++) {
          
                    // Replace every ch1 with ch2
                    // and every ch2 with ch1
                    if (str[i] == ch1)
                        str[i] = ch2;
          
                    else if (str[i] == ch2)
                        str[i] = ch1;
                }
            }
          
            return str;
    }
};

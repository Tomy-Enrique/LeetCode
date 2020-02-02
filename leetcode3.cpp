#include <iostream>
#include <string.h>
using namespace std;

int lengthOfLongestSubstring(char * s){
    int maxlen = 0;
    int len = 0;
    int start = 0;
    int slen = strlen(s);
    for(int i = 0; i < slen; i++){
        len++;
        for(int j = start; j != i; j++){;
            if(s[j] == s[i]){                
                start = j + 1;             
                len = 1;   
                break;
            }else{
                len = i - start + 1;
            }
        }
        if(len > maxlen){
            maxlen = len; 
        }
    }
    return maxlen;
}

int main()
{
    char* s1 = "abcabcbb";
    char* s2 = "pwwkew";
    char* s3 = "dvdf";
    cout << strlen(s3) << endl;
    cout << lengthOfLongestSubstring(s3);
}
/*
https://binarysearch.com/problems/Anagram-Substrings
*/

int solve(string s0, string s1) {
    int lens0 = s0.length(), lens1 = s1.length(), ans = 0, start = 0;

    vector<int> count(26,0), precount(26,0);

    for(int i = 0; i < lens0; i++){
        precount[s0[i]-'a']++;
    }

    for(int i = 0; i<lens1; i++){
        count[s1[i]-'a']++;
        if(i >= lens0-1){
            for(int j = 0; j < 26; j++){
                if(count[j] != precount[j]) break;
                if(j == 25) ans++;
            }
            count[s1[start++]-'a']--;
        }
    }
    return ans;

}
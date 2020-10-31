/*
basic idea is that you do bfs 
but whole idea is not only bfs rather what you do is first you check if the endword is present in wordlist
or not , if not present there's no meaning of finding it till last and thus you can return 0;
if that is present then what you do is,
you create a set wherein you have all the words of wordlist 
and 
also you create a queue wherein you push the first word which is the begin word
and then 
while queue is not null
    and you place only those words in the queue which can be obtained by just replacing one word and is present in the wordlist
    and thus if you have many words which can be obtained by change of one word for them you do not increase the depth because that's anyway is going to be redundant and so to address them you have another while loop nested 
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool ispresent=false;
        
        unordered_set<string> set;
        //inserting the word and also you are marking the presence of endword
        for(auto x:wordList){
            if(x==endWord){
                ispresent=true;
            }
            set.insert(x);
        }
        //if endword is present then its okay otherwise there's no meaning of heading ahead
        if(ispresent==false){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty()){
            //for avoiding redundant count
            depth+=1;
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                //for checking to every index of word
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    //replacing every index with all 26 letters
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(temp==curr){
                            continue;
                        }
                        if(temp==endWord){
                            return depth+1;
                        }
                        if(set.find(temp)!=set.end()){
                            q.push(temp);
                            set.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
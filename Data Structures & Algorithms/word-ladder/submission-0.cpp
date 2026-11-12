class Solution {
public:
    vector<string> getWildcards(string word){
        vector<string> wildcardList;
        for(int i=0;i<word.size();i++){
            string copy = word;
            copy[i] = '*';
            wildcardList.push_back(copy);
            // cout << copy << endl;
        }
        return wildcardList;
    }
    // also return startWord widcards in queue
    queue<string> createKeys(map<string,vector<pair<string,bool>>> &lookup,vector<string>& wordList,string beginWord){
        queue<string> q;
        for(string word : wordList){
            vector<string> wildcard = getWildcards(word); // complete this func
            for(auto const w: wildcard){
                lookup[w].push_back({word,true});
                if(word==beginWord){
                    q.push(w);
                }
            }
        }
        return q;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // for bat 
        // I create -> *at, b*t,ba* -> add bat as child of all these
        map<string,vector<pair<string,bool>>> lookup;
        queue<string> q = createKeys(lookup,wordList,beginWord);

        if(q.size()==0){
            vector<string> wildcards = getWildcards(beginWord);
            for(auto const w: wildcards){
                lookup[w].push_back({beginWord,false});
                q.push(w);
            }

        }

        int count = 1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string front = q.front();
                q.pop();
                // vector<pair<string,bool>> nbrs = lookup[front];
                for(auto &nbr: lookup[front]){
                    if(nbr.first==endWord) return count+1;
                    if(nbr.second){
                        vector<string> wildcards = getWildcards(nbr.first);
                        nbr.second = false;
                        for(string w: wildcards){
                            q.push(w);
                        }
                    }
                }
            }

            count++;
 
        }

        return 0;

    }
};

//brute force approach

// T.C = O(N^2) || S.C = O(26)
class Solution {
public:
    int partitionString(string s) {
        int count=0;        //HOw many unique string
        for(int i=0;i<s.size();i++){
            vector<bool> arr(26,false);     //you can choose other data structure link map,set in O(1) T.C
            int j=0;
            for(j=i;j<s.size();j++){
                if(arr[s[j]-'a']==true)break;
                int p=s[j]-'a';
                arr[p]=true;
            }
            count++;
            i=j-1;
        }
        return count;
    }
};


//Optimal approach 

// T.C = O(N) || S.C = O(26)


class Solution {
public:
    int partitionString(string s) {
        
        int count = 1;
        unordered_set<char>st; // You can use other data structure like (vector,hash_map)

        for(auto ch : s){

            if(st.find(ch) != st.end()){
                count++;
                st.clear(); //if we find out one unique string so find the next unique string so clear the previous string data
            }
            st.insert(ch);
        }

        return count;

    }
};


class Solution {
public:
    string reverseWords(string s) {
        // int start = 0, end = 0;
        // int temp = 0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]!=" "){
        //         end++;
        //     } else {
        //         whil
        //     }
        // }
        
        unordered_map<int,int> umap;
        int start = 0, end = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                end = i-1;
                umap.insert(make_pair(start,end));
                start = i+1;
            }
            
        }
        umap.insert(make_pair(start,s.size()-1));
        
        for(int i=0;i<=s.size();i++){
            if(umap.find(i)!=umap.end()){
                start = i, end = umap[i];
                while(start<end){
                    swap(s[start],s[end]);
                    start++, end--;
                }
                i = end+1;
            }
            
            
        }
        // while(start<end){
        //         swap(s[start],s[end]);
        //         start++, end--;
        //     }
        
        return s;
        
    }
};
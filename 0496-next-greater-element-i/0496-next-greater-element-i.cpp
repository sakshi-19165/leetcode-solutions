class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int , int> nextGre;
        for(int num:nums2){
            while (!st.empty()&&st.top()<num){
                nextGre[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            nextGre[st.top()]= -1;
            st.pop();
         
        }
        vector<int>result;
        for(int num:nums1){
        int i = nextGre[num];
        result.push_back(i);
        }
        return result;


        
    }
};
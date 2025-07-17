class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  // Default result is -1
        stack<int> st;  // Stack to keep indices

        // We iterate twice the array length to simulate circular behavior
        for (int i = 0; i < 2 * n; i++) {
            int curr = nums[i % n];  // Circular access

            // If current element is greater than the element at index on top of the stack
            while (!st.empty() && nums[st.top()] < curr) {
                result[st.top()] = curr;  // Found the next greater
                st.pop();
            }

            // For the first pass only, push index
            if (i < n) {
                st.push(i);
            }
        }

        return result;
    }
};
 using namespace std;
class Solution {


public:
    vector<int> topKFrequent(std::vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        
        for (int num : nums) {
            freq[num]++;
        }

        
        priority_queue<pair<int, int>, vector<pair<int, int>>,     std::greater<>> minHeap;
        
        for (const auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k) {
                minHeap.pop();  
            }
        }

        
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
//https://leetcode.com/problems/top-k-frequent-elements/submissions/1596231790/

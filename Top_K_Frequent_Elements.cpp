/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
  */
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    unordered_map<int,int> umap;
    for(auto x: nums)
    {
      umap[x]++;
    }
    priority_queue<pair<int,int>, vector< pair<int,int> >, greater<pair<int,int> >> pq;
    // PUSH ELE INTO MIN HEAP 
    for(auto x: umap)
    {
      pq.push(make_pair(x.second,x.first));
      // IF MIN HEAP SIZE IS GRETAER THAN K THEN POP , IT WILL POP THE SMALLEST FREQUENCY ELEMENT 
      if(pq.size()>k)
      {
        pq.pop();
      }
    }
    vector<int>ans;
    while(!pq.empty())
    {
      pair<int,int>temp=pq.top();
      pq.pop();
      ans.push_back(temp.second);
    }
    return ans;
  }
};

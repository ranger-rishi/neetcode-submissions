class KthLargest {
public:
priority_queue<int,vector<int>, greater<int>> pq;
int k;
    KthLargest(int l, vector<int>& nums) {
        // lets say that you build a min heap if the element on the top is less than the element encountered then you push that element into the heap , that way you'll always have a heap 
        // okay so lets make a min heap 
        k=l;
        for(int i= 0 ;i<nums.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push(nums[i]);
            }
            else
            {
                if(pq.top()<nums[i])
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<k)
        {
            pq.push(val);
        }
        else
        {
            if(pq.top()<val)
            {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

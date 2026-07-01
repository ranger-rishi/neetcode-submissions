class MedianFinder {
public:
    bool even;
    int size;
    priority_queue<int> left;
    priority_queue<int,vector<int>, greater<int>> right;
    pair<int,int> median;
    MedianFinder() {
        even=true;
        size=0;
        median={-1,-1};
    }
    
    void addNum(int num) {
        if(size==0)
        {
            median.first=num;
            even=false;
            size++;
            return;
           
        }
        else if(even)
        {
            size++;
            if(num<median.first)
            {
                right.push(median.second);
                median.second=-1;
                left.push(num);
            }
            else if(num>=median.first && num<median.second)
            {
                right.push(median.second);
                left.push(median.first);
                median.first=num;
                median.second=-1;
            }
            else
            {
                left.push(median.first);
                median.first=median.second;
                median.second=-1;
                right.push(num);
            }
            even=false;
        }
        else
        {
            size++;
            if(num<=median.first)
            {
                left.push(num);
                int x= left.top();
                left.pop();
                median.second=median.first;
                median.first=x;
            }
            else
            {
                right.push(num);
                int y = right.top();
                right.pop();
                median.second=y;
            }
            even=true;
        }
    }
    
    double findMedian() {
        if(even)
        {
            cout<<median.first<<" "<<median.second<<endl;
            return (median.first+median.second)/2.0;
        }
        else{
            cout<<median.first<<endl;
        return median.first;
        }
    }
};

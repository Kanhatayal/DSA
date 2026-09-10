// brute force with  O(n2logn2) time complexity and O(n^2) space complexity 
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double, pair<int, int>>> fractions;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double fraction = (double)arr[i]/arr[j];
                fractions.push_back({fraction, {arr[i], arr[j]}});
            }
        }

        sort(fractions.begin(), fractions.end());

        return {fractions[k-1].second.first, fractions[k-1].second.second};
    }
};


// optimization using heap (priority queue)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<double>> pq;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double fraction = (double)arr[i]/arr[j];

                pq.push(vector<double>{fraction, (double)arr[i], (double)arr[j]});

                if(pq.size() > k) pq.pop();
            }
        }
        auto vec = pq.top();
        vector<int> result(2);
        result[0] = vec[1];
        result[1] = vec[2];
        return result;
    }
};
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        // to find the total bookings of each flight
        vector<int> vec(n,0);
        for(int i = 0;i<bookings.size();i++){
            vec[bookings[i][0] - 1] += bookings[i][2];
            if(bookings[i][1] < n)
            {
                vec[bookings[i][1]] += bookings[i][2] * -1;
            }
        }
        for(int i = 1;i<n;i++)
        {
            vec[i] = vec[i] + vec[i-1];
        }
        
        return vec;
    }
};
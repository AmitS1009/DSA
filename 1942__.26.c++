class Solution {
public:

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);
        int targetFriendArrivalTime = times[targetFriend][0];

        sort(times.begin(), times.end());

        for(vector<int>& time : times){
          int arrival = time[0];
          int depart = time[0];

          for(int i=0; i<n; i++){
            if(chairs[i] <= arrival){
              chair[i] = depart;
              if(arrival == targetFriendArrivalTime) return i;
              break;
            }
          }
        }
        return -1;
    }
    
};






class Solution {
public:
    typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        priority_queue<P, vector<P>, greater<P> > occupied; //{departTime, chairNo}
        priority_queue<int, vector<int>, greater<int>> free; //min heap of unoccupied chairs
        
        int targetFriendArrival = times[targetFriend][0];
		
        //Sort based on arrival time
        sort(times.begin(),times.end());
        
		int chairNo = 0;

        for(int i = 0; i < n; i++) {
            int arrival  = times[i][0];
            int depart   = times[i][1];
            
            //free chairs accordingly
            while(!occupied.empty() && occupied.top().first <= arrival) {
                free.push(occupied.top().second); //this chair is now free
                occupied.pop();
            }

            if(free.empty()) {
                occupied.push({depart, chairNo});

                if(arrival == targetFriendArrival)
                    return chairNo;

                chairNo++;
            } else {
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendArrival) {
                    return leastChairAvailable;
                }
                occupied.push({depart, leastChairAvailable});
            }
        }

        return -1;
    }
    
};

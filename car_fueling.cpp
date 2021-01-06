/**
Program tackles the car refueling problem of optimising number of refuel stops given the car's tank, distance required, no. of stops.
1<=dist<=10^5, 1<=tank<=400, 1<=stops<=300
**/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.insert(stops.begin(), 0); //add starting point to stops 
    stops.push_back(dist); //add final destination to ensure vector does not access foreign memory later on when accessing index current_refills+1
    int num_refills = 0;
    int current_refills = 0;
    int last_refills = 0;
    if (tank>dist) //if tank does not need any refilling as it has sufficient capacity for the entire trip
    {
        return num_refills;
    }
    while (current_refills<= stops.size()-2){ //while the current refill index is less than the number of refill stops
        last_refills = current_refills; //update the last refill
        
        while ( (current_refills<=(stops.size()-2)) && ( (stops[current_refills+1]-stops[last_refills])<=tank)){ //maximise current refills index before actual refill
            current_refills+=1;
        }
        if (current_refills==last_refills){ //if the condition above fails, the trip is impossible
            return -1;
        }
        if (current_refills<=stops.size()-2){ //does actual refilling at the maximised current refill
            num_refills+=1;
        }
    }
    return num_refills;
}   


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

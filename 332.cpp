// 332. Reconstruct Itinerary


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> flightMap;
        vector<string> result;

        // Populate the flight map with each departure and arrival
        for (const auto& ticket : tickets) {
            flightMap[ticket[0]].insert(ticket[1]);
        }

        // Perform DFS traversal starting from "JFK"
        dfsTraversal("JFK", flightMap, result);

        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());

        return result;
    }

private:
    void dfsTraversal(const string& current,
                      unordered_map<string, multiset<string>>& flightMap,
                      vector<string>& result) {
        auto& destinations = flightMap[current];

        // Traverse all destinations in the order of their lexicographical
        // sorting
        while (!destinations.empty()) {
            // Get the smallest lexicographical destination and remove it from
            // the set
            auto nextDestination = *destinations.begin();
            destinations.erase(destinations.begin());

            // Recursively perform DFS on the next destination
            dfsTraversal(nextDestination, flightMap, result);
        }

        // Append the current airport to the result after all destinations are
        // visited
        result.push_back(current);
    }
};

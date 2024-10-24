// 378. Kth Smallest Element in a Sorted Matrix


class MinHeap {
public:
    // Custom comparison for the priority queue
    bool operator()(const tuple<int, int, int>& a,
                    const tuple<int, int, int>& b) {
        return get<0>(a) > get<0>(b);
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rowCount = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       MinHeap>
            minHeap;

        // Push the first element of each row into the minHeap
        for (int i = 0; i < min(rowCount, k); ++i) {
            minHeap.push(make_tuple(matrix[i][0], i, 0));
        }

        int numbersChecked = 0, smallestElement = 0;

        while (!minHeap.empty()) {
            // Get the smallest element from the heap
            auto [value, rowIndex, colIndex] = minHeap.top();
            minHeap.pop();
            smallestElement = value;
            numbersChecked++;

            // If we've checked k elements, return the kth smallest element
            if (numbersChecked == k)
                break;

            // If there is a next element in the current row, add it to the heap
            if (colIndex + 1 < matrix[rowIndex].size()) {
                minHeap.push(make_tuple(matrix[rowIndex][colIndex + 1],
                                        rowIndex, colIndex + 1));
            }
        }

        return smallestElement;
    }
};

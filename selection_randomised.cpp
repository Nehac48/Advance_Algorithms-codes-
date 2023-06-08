#include <ctime>
    #include <vector>
    #include <algorithm>
    #include <iterator>

    using namespace std;

    int randomizedSelect(vector<int> &array, int p, int r, int i);
    int randomizedPartition(vector<int> &array, int start, int end);
    void swap(int &i, int &j);

    int main() {
        srand(time(NULL));
        int maxSize = 10;
        vector<int> arr;

        for (int i = 0; i < maxSize; i++) {
            int n = rand() % 10000;
            arr.push_back(n);
        }

      

        int userChoice;
        cin >> userChoice;

        int loc = randomizedSelect(arr, 0, arr.size()-1, userChoice);

        cout << loc << endl;

        cout << "The array was:\n";
        copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        return 0;
    }

    int randomizedSelect(vector<int> &array, int p, int r, int i) {
        if (p == r)
            return array[p];

        if (i == 0)
            return -1;

        int mid = randomizedPartition(array, p, r);
        int k = mid - p + 1;

        if (k == i)
            return array[mid];
        else if (i < k)
            return randomizedSelect(array, p, mid-1, i);
        else
            return randomizedSelect(array, mid+1, r, i-k);
    }

    int randomizedPartition(vector<int> &array, int start, int end) {
        int pivotIdx = rand() % (end - start + 1) + start;
        int pivot = array[pivotIdx];

        swap(array[pivotIdx], array[end]);
        pivotIdx = end;

        int i = start - 1;

        for (int j = start; j <= end-1; j++) {
            if (array[j] <= pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }
        swap(array[i+1], array[pivotIdx]);
        return i+1;
    }

    void swap(int &i, int &j) {
        int temp = i;
        i = j;
        j = temp;
    }


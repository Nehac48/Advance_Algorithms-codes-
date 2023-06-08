#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int middle_index(vector<int> x){
    return (x.size()-1)/2;
}

vector<int> merge_tuple(vector<int> a, vector<int> b){
    vector<int> c;
    while (a.size() != 0 && b.size() != 0){
        if (a[0] < b[0]){
            c.push_back(a[0]);
            a.erase(a.begin());
        }
        else{
            c.push_back(b[0]);
            b.erase(b.begin());
        }
    }
    if (a.size() == 0){
        c.insert(c.end(), b.begin(), b.end());
    }
    else{
        c.insert(c.end(), a.begin(), a.end());
    }
    return c;
}

vector<int> mergesort_tuple(vector<int> x){
    if (x.size() == 0 || x.size() == 1){
        return x;
    }
    else{
        int middle = x.size()/2;
        vector<int> a = mergesort_tuple(vector<int>(x.begin(), x.begin()+middle));
        vector<int> b = mergesort_tuple(vector<int>(x.begin()+middle, x.end()));
        return merge_tuple(a,b);
    }
}

vector<vector<int> > lol(vector<int> x, int k){
    vector<vector<int> > lst;
    for (int i = 0; i < x.size(); i += k){
        lst.push_back(vector<int>(x.begin()+i, x.begin()+i+k));
    }
    return lst;
}

vector<int> ChoosePivot(vector<int> x){
    if (x.size() <= 5){
        return mergesort_tuple(x)[middle_index(x)];
    }
    else{
        vector<vector<int> > lst = lol(x,5);
        vector<int> C;
        for (int i = 0; i < lst.size(); i++){
            C.push_back(mergesort_tuple(lst[i])[middle_index(lst[i])]);
        }
        return ChoosePivot(C);
    }
}

vector<int> partition(vector<int> x, int pivot_index = 0){
    int i = 0;
    if (pivot_index != 0){
        swap(x[0], x[pivot_index]);
    }
    for (int j = 0; j < x.size()-1; j++){
        if (x[j+1] < x[0]){
            swap(x[j+1], x[i+1]);
            i += 1;
        }
    }
    swap(x[0], x[i]);
    return x;
}

int DSelect(vector<int> x, int k){
    if (x.size() == 1){
        return x[0];
    }
    else{
        vector<int> xpart = partition(x, ChoosePivot(x)[1]);
        x = xpart;
        int j = xpart[1];
        if (j == k){
            return x[j];
        }
        else if (j > k){
            return DSelect(vector<int>(x.begin(), x.begin()+j), k);
        }
        else{
            k = k - j - 1;
            return DSelect(vector<int>(x.begin()+j+1, x.end()), k);
        }
    }
}

int main(){
    vector<int> arr;
    for (int i = 100; i > 0; i--){
        arr.push_back(i)
        }
        }
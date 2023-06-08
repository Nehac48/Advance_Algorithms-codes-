#include<bits/stdc++.h>
using namespace std;

//randomly shuffle then quicksort
void shuffle(vector<int>&v,int s,int e){
    srand(time(NULL));
    int i,j,temp;
    for(int i=e;i>0;i--){
        //create random index
        j=rand()%(i+1);
        swap(v[i],v[j]);
    }
}
int partition(vector<int>&v, int s, int e) {

    int pivot = v[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(v[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(v[pivotIndex], v[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(v[i] <= pivot) 
        {
            i++;
        }

        while(v[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(v[i++],v[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(vector<int>&v, int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenfe
    int p = partition(v, s, e);

    //left part sort karo
    quickSort(v, s, p-1);

    //right wala part sort karo
    quickSort(v, p+1, e);

}

int main() {

    int  n;

srand(time(0));

n = rand() % 10000;

   vector<int>v(n,1);
   shuffle(v,0,n-1);
  quickSort(v,0,n-1);
  for (int i = 0; i < n; i++) {
        cout<<v[i];
  }


    return 0;
}
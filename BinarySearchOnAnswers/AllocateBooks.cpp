#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

// func to count how many students are needed if max pages per student is 'pages'
int countStudents(vector<int> &arr, int pages) {
    int stud = 1;
    long long pagesStud = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > pages) {
            return INT_MAX; // cant assign this book, cuz min is 'pages'
        }
        if(pagesStud + arr[i] <= pages) {
            pagesStud += arr[i];
        }
        else{
            stud = stud + 1;
            pagesStud = arr[i];
        }
    }
    return stud;
}

int findPages(vector<int> &arr, int k){
    if(k > arr.size()){
        return -1; // not enough books for students
    }
    int low = *max(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int students = countStudents(arr, mid);
        if(students > k){
            low = mid + 1; // too many students, so need more pages -> eliminate left
        }
        else{
            ans = mid; // may or may not be the ans
            high = mid - 1; // eliminate right half
        }
    }
    return ans;
}

int main() {
    vector<int> books = {12, 34, 67, 90}; // Pages in each book
    int students = 2;

    int result = findPages(books, students);

    if (result != -1)
        cout << "Minimum number of pages: " << result << endl;
    else
        cout << "Not enough books for students!" << endl;

    return 0;
}
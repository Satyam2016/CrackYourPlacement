// Allocate Minimum Pages
// Difficulty: MediumAccuracy: 35.51%Submissions: 198K+Points: 4
// You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of pages in a book allotted to a student should be the minimum, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

// Examples:

// Input: n = 4, arr[] = [12, 34, 67, 90], m = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113, which is selected as the output.
// Input: n = 3, arr[] = [15, 17, 20], m = 5
// Output: -1
// Explanation: Allocation can not be done.

class Solution{
    
    public:
    int countStudents(const vector<int> &arr, int pages) {
        int n = arr.size();
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                // Add pages to current student
                pagesStudent += arr[i];
            } else {
                // Add pages to next student
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

    // Function to find minimum number of pages
    long long findPages(int n, int arr[], int m) {
        if (m > n) return -1;

        vector<int> books(arr, arr + n); 

        int low = *max_element(books.begin(), books.end());
        int high = accumulate(books.begin(), books.end(), 0);
        int result = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(books, mid);
            if (students > m) {
                low = mid + 1;
            } else {
                high = mid - 1;
                result = mid;
            }
        }
        return result;
    }
};
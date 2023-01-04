#include <bits/stdc++.h>
using namespace std;

class Recursion
{
public:
    bool checkSortedOrNot(int *arr, int n)
    {
        if (n == 0 || n == 1)
        {
            return true;
        }

        if (arr[0] > arr[1])
        {
            return false;
        }

        bool ans = checkSortedOrNot(arr + 1, n - 1);
        return ans;
    }

    void print(int n)
    {

        if (n == 0)
        {
            return;
        }
        print(n - 1);
        cout << n << endl;
    }

    int jumps(int n)
    {

        if (n == 1 || n == 0)
        {
            return 1;
        }

        return jumps(n - 1) + jumps(n - 2);
    }

    int sum(int arr[], int n)
    {
        if (n == 0)
        {
            return 0;
        }

        int ans = sum(arr + 1, n - 1);
        return arr[0] + ans;
    }

    bool linearSearch(int arr[], int n, int target)
    {

        if (n == 0)
        {
            return false;
        }

        if (arr[0] == target)
        {
            return true;
        }

        return linearSearch(arr + 1, n - 1, target);
    }

    bool binarySearch(int arr[], int start, int end, int target)
    {
        int mid = start + ((end - start) >> 1);
        if (start > end)
        {
            return false;
        }
        if (arr[mid] == target)
        {
            return true;
        }
        if (arr[mid] > target)
        {
            return binarySearch(arr, start, mid - 1, target);
        }
        else
        {
            return binarySearch(arr, mid + 1, end, target);
        }
    }

    string Reverse(string s)
    {
        if (s.length() == 0)
        {
            return "";
        }
        string ans = Reverse(s.substr(1));
        return ans + s[0];
    }

    bool checkPallindrome(string s)
    {
        if (s.length() == 0)
        {
            return true;
        }
        int n = s.length();

        if (s[0] != s[n - 1])
        {
            return false;
        }

        return checkPallindrome(s.substr(1, n - 2));
    }

    int power(int a, int b)
    {

        if (b == 0)
        {
            return 1;
        }
        if (b == 1)
        {
            return a;
        }

        int ans = power(a, b / 2);
        ans = ans * ans;

        if (b % 2 == 0)
        {
            return ans;
        }
        else
        {
            return ans * a;
        }
    }

    int firstOccurance(int *arr, int i, int n, int target)
    {
        if (i == 0)
        {
            return -1;
        }

        if (arr[i] == target)
        {
            return i;
        }

        int ans = firstOccurance(arr, i - 1, n, target);
        return ans;
    }
    void replacePI(string s)
    {
        if (s.length() == 0)
            return;

        if (s[0] == 'p' && s[1] == 'i')
        {
            cout << "3.14";
            replacePI(s.substr(2));
        }
        else
        {
            cout << s[0];
            replacePI(s.substr(1));
        }
    }

    void towerOfHanoi(int n, char src, char helper, char dest)
    {

        if (n == 1)
        {
            cout << "Move from " << src << " to " << dest << endl;
            return;
        }

        towerOfHanoi(n - 1, src, dest, helper);
        cout << "Move from " << src << " to " << dest << endl;
        towerOfHanoi(n - 1, helper, src, dest);
    }

    string removeAllDuplicates(string s)
    {

        if (s.length() == 0)
            return "";

        if (s[0] == s[1])
        {
            return removeAllDuplicates(s.substr(1));
        }
        else
        {
            return (s[0] + removeAllDuplicates(s.substr(1)));
        }
    }

    string moveAllXToTheEnd(string s)
    {
        if (s.length() == 0)
        {
            return "";
        }

        if (s[0] == 'x')
        {
            return moveAllXToTheEnd(s.substr(1)) + 'x';
        }
        return (s[0] + moveAllXToTheEnd(s.substr(1)));
    }

    void printAllSubsequences(string s, string ans)
    {
        if (s.length() == 0)
        {
            cout << ans << endl;
            return;
        }

        printAllSubsequences(s.substr(1), ans);
        printAllSubsequences(s.substr(1), ans + s[0]);
    }
    string arr[4] = {".", ".", "abc", "def"};

    void keypadProblem(string s, string ans)
    {

        if (s.length() == 0)
        {
            cout << ans << endl;
            return;
        }

        string comb = arr[s[0] - '0'];

        for (int i = 0; i < comb.length(); i++)
        {
            keypadProblem(s.substr(1), ans + comb[i]);
        }
    }

    void Permutations(string s, string ans)
    {

        if (s.length() == 0)
        {
            cout << ans << endl;
            return;
        }

        for (int i = 0; i < s.length(); i++)
        {
            Permutations(s.substr(0, i) + s.substr(i + 1), ans + s[i]);
        }
    }

    int countPath(int s, int e)
    {
        if (s == e)
        {
            return 1;
        }
        if (s > e)
        {
            return 0;
        }
        int count = 0;

        for (int i = 1; i <= 6; i++)
        {
            count += countPath(s + i, e);
        }
        return count;
    }

    int PathInaMaze(int n, int i, int j)
    {
        if (i == n - 1 && j == n - 1)
        {
            return 1;
        }

        if (i == n || j == n)
            return 0;

        return PathInaMaze(n, i + 1, j) + PathInaMaze(n, i, j + 1);
    }

    void solve(vector<int> nums, vector<int> output, int index)
    {
        if (index >= nums.size())
        {
            for (auto x : output)
            {
                cout << x << " ";
            }
            cout << endl;
            return;
        }

        output.push_back(nums[index]);
        solve(nums, output, index + 1);
        output.pop_back();
        solve(nums, output, index + 1);
    }

    int knapSack(vector<int> wt, vector<int> values, int W, int index)
    {
        if (index >= wt.size() || (W <= 0))
        {
            return 0;
        }

        if (wt[index] > W)
        {
            return knapSack(wt, values, W, index + 1);
        }

        return (max(knapSack(wt, values, W - wt[index], index + 1) + values[index], knapSack(wt, values, W, index + 1)));
    }

    void solve(string s, int index, string output, vector<string> &ans)
    {
        if (index >= s.length())
        {
            ans.push_back(output);
            return;
        }

        string value = arr[s[index] - '0'];

        for (int i = 0; i < value.length(); i++)
        {
            output = output + value[i];
            solve(s, index + 1, output, ans);
            output.pop_back();
        }
    }

    vector<string> keypadProblem(string s)
    {
        vector<string> ans;
        string output = "";
        int index = 0;
        solve(s, index, output, ans);

        return ans;
    }
    
bool subsWithGivenSum(int i, int n, vector<int> &arr, vector<int> &sol, int sum, int SumAtEachStep)
{
    if (i >= n)
    {
        if (sum == SumAtEachStep)
        {
            for (auto &x : sol)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    sol.push_back(arr[i]);
    SumAtEachStep += arr[i]; // SumAtEachStep+ arr[i]
    if (subsWithGivenSum(i + 1, n, arr, sol, sum, SumAtEachStep))
    {
        return true;
    }
    SumAtEachStep -= arr[i]; // Then no need for this step
    sol.pop_back();

    if (subsWithGivenSum(i + 1, n, arr, sol, sum, SumAtEachStep))
    {
        return true;
    }

    return false;
}

set<vector<int>> S;
// Can take an element any number of times...
void getTheTargetSum(int idx, int n, vector<int> &arr, int target, vector<int> &sol)
{
    if (target < 0)
        return;
    if (idx == n)
    {
        if (target == 0)
        {
            for (auto &x : sol)
                cout << x << " ";
            cout << endl;

            /* To get only unique subsequences
            for (auto it = S.begin(); it != S.end(); it++)
                {
                    for (auto &x : *it)
                    {
                    cout << x << " ";
                    }
                cout << endl;
            }*/
        }
        return;
    }

    sol.push_back(arr[idx]);
    // target -= arr[idx];
    getTheTargetSum(idx, n, arr, target - arr[idx], sol);
    sol.pop_back();
    // target += arr[idx];
    getTheTargetSum(idx + 1, n, arr, target, sol);
}

// unique subsequences
void uniqueSubsequences(int idx, int target, int n, vector<int> &arr, vector<int> sol)
{
    if (target == 0)
    {
        for (auto &x : sol)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if ((i > idx) && (arr[i] == arr[i - 1]))
            continue;
        if (arr[i] > target)
            break;

        sol.push_back(arr[i]);
        subsetSum(i + 1, target - arr[i], n, arr, sol);
        sol.pop_back();
    }
}

void powerSet(int n, vector<int> &arr)
{
    for (int i = 0; i < pow(2, n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                cout << "{}";
                continue;
            }
            if (i & (1 << j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}

void recursivePowerSetSum(int idx, int n, int sum, vector<int> &arr, vector<int> &sol)
{
    if (idx >= n)
    {
        sol.push_back(sum);
        return;
    }

    recursivePowerSetSum(idx + 1, n, sum + arr[idx], arr, sol);
    recursivePowerSetSum(idx + 1, n, sum, arr, sol);
}

void printUniqueSubsets(int idx, int n, vector<int> &arr, vector<int> &sol)
{
    for (auto &x : sol)
        cout << x << " ";
    cout << endl;

    for (int i = idx; i < n; i++)
    {
        if ((i != idx) && (arr[i] == arr[i - 1]))
            continue;
        sol.push_back(arr[i]);
        printUniqueSubsets(i + 1, n, arr, sol);
        sol.pop_back();
    }
}

void printPermutations(int n, vector<int> &arr, vector<int> &sol, map<int, int> &m)
{
    if (sol.size() == n)
    {
        for (auto &x : sol)
            cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (m[i] == 0)
        {
            sol.push_back(arr[i]);
            m[i] = 1;
            printPermutations(n, arr, sol, m);
            m[i] = 0;
            sol.pop_back();
        }
    }
}

void permutationsWithSwap(int idx, int n, vector<int> &arr)
{
    if (idx >= n)
    {
        for (auto &x : arr)
        {
            cout << x;
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < n; i++)
    {
        swap(arr[i], arr[idx]);
        permutationsWithSwap(idx + 1, n, arr);
        swap(arr[i], arr[idx]);
    }
}

void Reverse(vector<int> &arr, int start, int end)
{
    while (start <= end)
    {
        swap(arr[start++], arr[end--]);
    }
}

void nextPermutation(vector<int> &arr)
{
    int n = nums.size(), i, j;
    for (i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            break;
        }
    }

    if (i < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (j = n - 1; j > i; j--)
        {
            if (nums[j] > nums[i])
            {
                swap(nums[i], nums[j]);
                break;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
}
};

int main()
{
    vector<string> ans = keypadProblem("23");
    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}

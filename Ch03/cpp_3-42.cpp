#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec = {0,4,2,6,7};
    const size_t vec_t = vec.size();
    int arr[vec_t];
    for (size_t i = 0; i < vec_t; i++)
    {
        /* code */
        arr[i] = vec[i];
    }
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
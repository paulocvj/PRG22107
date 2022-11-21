#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    vector<int> vec;
    vector<int>::iterator i;

    while (x != -2147483648)
    {
        cin >> x;
        vec.push_back(x);
    }
    vec.pop_back();

    for (i = vec.begin(); i != vec.end(); i++)
        cout << *i << " ";
    cout << endl;

    cout << "Min element: " << *min_element(vec.begin(), vec.end()) << endl;
    cout << "Max element: " << *max_element(vec.begin(), vec.end()) << endl;

    sort(vec.begin(), vec.end());

    for (i = vec.begin(); i != vec.end(); i++)
        cout << *i << " ";
    cout << endl;

    return 0;
}
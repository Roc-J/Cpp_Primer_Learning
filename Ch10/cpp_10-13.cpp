#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool MoreString(const string& s1)
{
    return s1.size() >= 5;
}

int main()
{
    vector<string> svec ={"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    auto it = partition(svec.begin(), svec.end(), MoreString);
    
    for (auto itr = svec.cbegin(); itr != it; ++itr)
		std::cout << *itr << " ";
    cout << endl;
    
    while (it != svec.end())
    {
        cout << *it << " ";
        ++it;
    }
    return 0;
}
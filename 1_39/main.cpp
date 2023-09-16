#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <filesystem>
#include <memory>
#include <map>
#include <set>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/adaptors.hpp>
#include <chrono>
#include <thread>
#include <compare>
#include <initializer_list>

using namespace std;



int main()
{
    setlocale(LC_ALL, "");

    vector<char> znaki = { 'x','P','Q','4','\n','%','u','@','e',
    'T','B','$', '!',':','"','1','<','d','k','L','$',')','$','B','x',
    'w','q','P','c','X','B','>','?','[','r','x','$', '#','}','|','d','l','n','b','V','!'};

    unsigned sum = 0;

    for ( const auto &e : znaki)
    {
        if (e >= 48 and e <= 48+9)
        {
            sum += e - 48;
            // sum += static_cast<int>(e);
            cout << e << " ";
        }
    }

    cout << "\nSuma znaków: " << sum << endl;

    char s = znaki.front();
    char k = znaki.back();

    for (int i=0; i<znaki.size(); i++)
    {
        if (znaki.at(i) == s or znaki.at(i) == k)
        {
            znaki.erase(znaki.begin() + i);
            i--;
            // continue;
        }
    }

    for (int i=0; i<znaki.size(); i++)
    {
        bool doublet = false;
        for (int check = i + 1; check<znaki.size(); check++)
        {
            if (znaki.at(i) == znaki.at(check))
            {
                doublet = true;
                znaki.erase(znaki.begin() + check);
                check--;
            }
        }
        if (doublet)
        {
            cout << znaki.at(i) << endl;
        }
    }
    

    return EXIT_SUCCESS;
}

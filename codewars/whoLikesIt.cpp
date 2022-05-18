#include <sstream>
#include <cstdio>
#include <vector>
#include <string>


std::string likes(const std::vector<std::string> &names)
{
    size_t count_names = names.size();

    if (count_names == 0) {
        return "no one likes this";
    }

    std::stringstream ss;
    if (count_names == 1) {
        ss << names[0] << " likes this";
        return ss.str();
    }

    if (count_names == 2) {
        ss << names[0] << " and " << names[1] << " like this";
        return ss.str();
    }

    if (count_names == 3) {
        ss << names[0] << ", " << names[1] << " and " << names[2] << " like this";
        return ss.str();
    }

    ss << names[0] << ", " << names[1] << " and " << (count_names - 2) << " others like this";
    return ss.str();
}


int main()
{
    printf("%s\n", likes({"Peter"}).c_str());
    printf("%s\n", likes({"Peter", "Huy"}).c_str());
    printf("%s\n", likes({"Peter", "Huy", "asdf"}).c_str());
    printf("%s\n", likes({"Peter", "Huy", "asdf", "pasidf"}).c_str());
    return 1;
}


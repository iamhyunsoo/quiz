#include <string>
#include <vector>

using namespace std;

std::string simplifyPath(std::string path) 
{
    //path looks like " /home/hyunsoo/../jenna/Downloads ", and it should be like " /home/jenna/Downloads "
    std::string ret;
    std::vector<std::string> vec;  //each dir name will be pushed back into here without slashes. [Ex: vec = {home, hyunsoo, jenna . . . .}]

    int size = path.size();
    for(int i = 1, c; i < size; i++)    //I skip 0th index, because it must be just a slash("/")
    {
        c = path[i];
        if (c != '/')
        {
            ret.append(1, c);
        }
        if (c == '/' || i == size - 1)  // ( i == size - 1 ) is needed for last index.
        {
            if (ret == "..")
            {
                if (vec.size())
                {
                    vec.pop_back();
                }
            }
            else if (ret != "." && ret.size())
            {
                vec.push_back(ret);
            }
            ret = "";
        }
    }
    ret = vec.size() ? "" : "/";
    for (std::string& word : vec)
    {
        ret += "/" + word;
    }
    return ret;
}
std::unordered_map<std::string, int> ESG = {{
    {"C", 0},
    {"CC", 1},
    {"CCC", 2},
    {"B", 3},
    {"BB", 4},
    {"BBB", 5},
    {"A", 6},
    {"AA", 7},
    {"AAA", 8},
}};
std::unordered_map<int, std::string> ESGreverse = {{
    {0, "C"},
    {1, "CC"},
    {2, "CCC"},
    {3, "B"},
    {4, "BB"},
    {5, "BBB"},
    {6, "A"},
    {7, "AA"},
    {8, "AAA"},
}};

struct Node
{
    std::string mIssuer;
    int mRating;
    Node *mParentNode;
    Node(std::string issuer, std::string rating, Node *parentNode = nullptr)
    {
        mIssuer = issuer;
        mRating = ESG[rating];
        mParentNode = parentNode;
    }
};

class Answer
{
public:
    void FindRate(std::vector<std::vector<std::string>> list, std::string inp)
    {
        std::unordered_map<std::string, std::unordered_set<Node *>> relation;
        std::unordered_map<std::string, Node *> dict;
        for (auto const &esg : list)
        {
            std::string issuer = esg[0];
            std::string parent = esg[1];
            std::string rate = esg[2];

            auto node = new Node(issuer, rate);
            if (parent != "")
                relation[parent].insert(node);

            dict[issuer] = node;
        }

        for (auto const &esg : list)
        {
            for (auto &child : relation[esg[1]])
            {
                child->mParentNode = dict[esg[1]];
            }
        }

        bool bIsCyclic = false;
        for (auto &node : dict)
        {
            std::unordered_set<Node *> visited;
            if (IsCyclic(node.second, visited))
            {
                bIsCyclic = true;
                break;
            }
        }
        std::cout << (bIsCyclic ? "cyclic" : "noncyclic") << std::endl;

        int maxRate = dict[inp]->mRating;
        FindMaxRate(dict[inp], maxRate);
        printf("%s\n%s\n", inp.c_str(), ESGreverse[maxRate].c_str());

        // free memories
        for (auto &node : dict)
        {
            delete node.second;
        }
    }

private:
    void FindMaxRate(Node *node, int &rate)
    {
        if (node->mParentNode != nullptr)
        {
            rate = std::max(rate, node->mParentNode->mRating);
            FindMaxRate(node->mParentNode, rate);
        }
        else
        {
            return;
        }
    }

    bool IsCyclic(Node *node, std::unordered_set<Node *> &visited)
    {
        if (visited.find(node) == visited.end())
        {
            visited.insert(node);
            if (node->mParentNode && IsCyclic(node->mParentNode, visited))
            {
                return true;
            }
        }
        else
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Answer as;
    as.FindRate({{"A", "B", "CCC"}, {"B", "C", "A"}, {"D", "B", "B"}, 
                 {"E", "D", "AAA"}, {"G", "D", "CCC"}, {"H", "C", "BB"}, 
                 {"I", "H", "AA"}, {"C", "", "BBB"}, {"F", "", "BB"}, 
                 {"J", "K", "C"}, {"K", "", "CC"}, {"L", "I", "AA"}, 
                 {"H", "", "BB"}},
                "C");

    as.FindRate({{"A", "B", "AA"}, {"B", "C", "A"}, {"D", "B", "B"}, 
                 {"E", "D", "AAA"}, {"G", "D", "CCC"}, {"H", "C", "BB"}, 
                 {"I", "H", "AA"}, {"C", "", "BBB"}, {"F", "", "BB"}, 
                 {"J", "K", "C"}, {"K", "", "CC"}, {"L", "I", "AA"}, 
                 {"H", "L", "BB"}},
                "A");
    return 0;
}

/*
ESG Issuer Data is of the form:
-------------------------------
Issuer | Parent | ESG Rating
A23444 | B23444 | AA
B23444 | C23444 | A
D23444 | B23444 | B
E23444 | D23444 | AAA
G23444 | D23444 | CCC
H23444 | C23444 | BB
I23444 | H23444 | AA
C23444 |        | BBB
F23444 |        | BB
J23444 | K23444 | C
K23444 |        | CC
L23444 | I23444 | AA
H23444 | L23444 | BB
-------------------------------

Assumptions that can be made:
1. If asked to find a min or max rating, given an issuer,
consider all the issuers in the path from the given issuer to
the ultimate parent.
2. Rating order AAA > AA > A > BBB > BB > B > CCC > CC > C

Your assignment:
- Come up with a Data Structure to hold this type of data.
- Write an algorithm to check if the relations above are cyclic in nature.
- (Convert the Data Structure to a directed one assuming the direction is from the Issuer to its parent) Find the issuer with max rating.

Input:
The issuer table, with respective columns:
Issuer, Parent, ESGRating, separated by '|'

Output:
- If relations from the input table are cyclic in nature (cyclic or noncyclic)
- issuer with max rating, return None if invalid/not applicable
- max rating, return None if invalid/not applicable
*/

/*
 * Complete the 'longest_name_chain' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_STRING_ARRAY list_of_names as parameter.
 
 We define a name chain like so:
 - A name is made up of first_name and last_name strings in a 2-item list 
   represented like [first_name, last_name], for example ['bob', 'ross'].
 - Names A and B form a name chain if the last name of A is the first name
   of B, such that A[1]==B[0].
 - Names A, B and C form a name chain if A[1] == B[0] and B[1] == C[0],
   and so on and so forth.
  
 Given a list of names, return the length of the longest name chain (as an int)
 that can be formed using names in the list.
 
 You may use intermediate data structures to store names if you find it helpful.
 
 Assume that the input list will not contain duplicate names, ex:[['bob','ross'], ['bob','ross']],
 or cyclical name chains, ex: [['bob','ross'], ['ross','bob']]
 
 
 Clarifying Points:
 - The same first name or last name may appear multiple times - no duplicate names does not exclude
 possibilities like: [['bob','ross'], ['bob','miller']]
 
 - All names will have a first name and a last name only.
 - A name chain may be of length 1.
 - The longest name chain when there are no names is of length 0.
 
 Examples:
 { {"bob", "ross"}, {"ross", "miller"}, {"brown", "cow"}, {"ross", "brown"} }     => 3
 { {} }                                                                           => 0
 { {"bobby", "bob"} }                                                             => 1
 { {"anna", "bob"}, {"bob", "casey"}, {"casey", "dean"} }                         => 3
 { {"bob", "ross"}, {"ross", "miller"}, {"brown", "cow"}, {"ross", "brown"}, {"me", "crazy"}, {"miller", "good"}, {"good", "me"} }   => 5
 */

struct Node
{
    string mFirst;
    string mLast;
    Node* mParent;
    Node(string first, string last, Node* parent = nullptr)
    {
        mFirst = first;
        mLast = last;
        mParent = parent;
    }
};

int GetLength(Node* node)
{
    if (node->mParent == nullptr)
    {
        return 1;
    }
    return GetLength(node->mParent) + 1;
}

int longest_name_chain(vector<vector<string>> list_of_names) 
{
    if (list_of_names.size() == 0 || list_of_names[0].size() == 0) return 0;

    std::unordered_map<string, unordered_set<Node*>> firstNames;
    std::unordered_map<string, unordered_set<Node*>> lastNames;
    std::unordered_set<Node*> nodes;
    for (auto const& name : list_of_names)
    {
        auto node = new Node(name[0], name[1]);
        firstNames[name[0]].insert(node);
        lastNames[name[1]].insert(node);
        nodes.insert(node);
    }

    for (auto const& name : list_of_names)
    {
        for (auto& x : firstNames[name[1]])
        {
            for (auto& y : firstNames[name[0]])
            {
                if (y->mLast == x->mFirst)
                {
                    x->mParent = y;
                }
            }
        }

        for (auto& x : lastNames[name[0]])
        {
            for (auto& y : lastNames[name[1]])
            {
                if (x->mLast == y->mFirst)
                {
                    y->mParent = x;
                }
            }
        }
    }
    int longest{ 0 };
    for (auto const& node : nodes)
    {
        longest = std::max(longest, GetLength(node));
    }
    return longest;
}

int main()
{
    cout << longest_name_chain({ {"bob", "ross"}, {"ross", "miller"}, {"brown", "cow"}, {"ross", "brown"} }) << endl;
    cout << longest_name_chain({ {} }) << endl;
    cout << longest_name_chain({ {"bobby", "bob"} }) << endl;
    cout << longest_name_chain({ {"anna", "bob"}, {"bob", "casey"}, {"casey", "dean"} }) << endl;
    cout << longest_name_chain({ {"bob", "ross"}, {"ross", "miller"}, {"brown", "cow"}, {"ross", "brown"}, {"me", "crazy"}, {"miller", "good"}, {"good", "me"} }) << endl;
}

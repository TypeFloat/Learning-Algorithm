#include "utils.h"
#include "tree.h"

using namespace std;

vector<vector<int>> levelOrder(Node *root)
{
     if (root == nullptr)
        return {};
    queue<Node *> my_queue;
    my_queue.push(root);
    int count = 1;
    vector<vector<int>> rtn;
    while (!my_queue.empty())
    {
        vector<int> layer;
        int tmp = 0;
        for (int i = 0; i < count; ++i)
        {
            Node *tmp_ptr = my_queue.front();
            layer.emplace_back(tmp_ptr->val);
            for (Node *child : tmp_ptr->children)
            {
                my_queue.push(child);
                tmp++;
            }
            my_queue.pop();
        }
        count = tmp;
        rtn.emplace_back(layer);
    }
    return rtn;
}
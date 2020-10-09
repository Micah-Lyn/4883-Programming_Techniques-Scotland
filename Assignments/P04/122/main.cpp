#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> v;

struct node
{
    node() : val(-1), left(nullptr), right(nullptr) { }
  
    node* left;
    node* right;
     int val;
};

bool passed;

void add(node** r, int val, string& ds, size_t it)
{
    if (!*r)
        *r = new node;

    if (it == ds.size())
    {
        if ((*r)->val != -1)
         passed = false;

        (*r)->val = val;
    }
    else if (ds[it] == 'R')
        add(&(*r)->right, val, ds, it + 1);
    else
        add(&(*r)->left, val, ds, it + 1);
}

v bfs(node* r)
{
    queue<node*> Q;

    Q.push(r);

    v val;

    while (!Q.empty())
    {
        r = Q.front();
        
        Q.pop();

        val.push_back(r->val);

        if (r->left) 
        {
          Q.push(r->left);

        }
        if (r->right)
        {
          Q.push(r->right);

        }
    }
    return val;
}

int main()
{
    string str;

    while (cin >> str)
    {
        node* root = nullptr;
        passed = true;

        while (str != "()")
        {
            string pos, pos1;

            int i = 1;
            while (str[i] != ',') 
            {
             pos += str[i++];
            }

            while (str[i] != ')')
            {
             pos1 += str[i++];
            }

            add(&root, stoi(pos), pos1, 1);

            cin >> str;
        }

        v vi;

        if (passed)
        {
            vi = bfs(root);
            
            for (int left : vi)
                if (left == -1)
                    passed = false;
        }
        
        if (passed)
        {
            for (int i = 0; i < vi.size(); ++i)
            {
                cout << vi[i];

                if (i != vi.size() - 1) 
                  cout << ' ';
            }
        }
        else
        {
            cout << "not complete";
        }
        cout << endl;

        delete root;
    }
}
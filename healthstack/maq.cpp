
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// } Driver Code Ends
 
class Node{
    public:
    
    Node *left, *right;
    int freq;
    char ch;
    
    
    Node(int f, char c) {
        left = right = NULL;
        this->freq = f;
        this->ch = c;
    }
};
 
class Solution
{
public:
 
    struct compare {
 
            bool operator()(Node* l, Node* r)
         
            {
                return (l->freq > r->freq);
            }
        };
        
        void traverse(Node* root, string s, vector<string>& vec) {
    if (root == nullptr) {
        return;
    }

    if (root->ch != '0') {
        vec.push_back(s);
    }

    traverse(root->left, s + '0', vec);
    traverse(root->right, s + '1', vec);
}

 
vector<string> huffmanCodes(string S,vector<int> f,int N)
{
    priority_queue<Node*, vector<Node*>,compare> pq;
    
    for(int i=0;i<f.size();i++) {
        Node *n = new Node(f[i],S[i]);
        pq.push(n);
    }
    
    while(pq.size() != 1) {
        Node *node1 = pq.top();
        pq.pop();
        Node *node2 = pq.top();
        pq.pop();
        
        Node *parent = new Node(node1 -> freq + node2 -> freq, '0');
        
        if(node1 -> freq < node2 -> freq) {
            parent -> left = node1;
            parent -> right = node2;
        }
        else if(node1 -> freq > node2 -> freq) {
            parent -> left = node2;
            parent -> right = node1;
        }
        else{
            parent -> left = node1;
            parent -> right = node2;
        }
        
        pq.push(parent);
    }
    
    vector<string> vec;
    
    string s = "";
    
    traverse(pq.top(),s,vec);
    return vec;
}
};
 
//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    string S;
    cin >> S;
    int N = S.length();
    vector<int> f(N);
    for(int i=0;i<N;i++){
        cin>>f[i];
    }
    Solution ob;
    vector<string> ans = ob.huffmanCodes(S,f,N);
    for(auto i: ans)
    cout << i << " ";
    cout << "\n";
    }
return 0;
}
// } Driver Code Ends
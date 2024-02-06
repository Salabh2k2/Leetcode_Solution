struct Node{
    Node* links[2];
    bool containskey(int bit)
    {
        return (links[bit]!=NULL);
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node* node = root;
        for(int i = 31; i >= 0; i--) // Fix: Corrected loop
        {
            int bit = (num >> i) & 1; // Fix: Corrected bit extraction
            if(!node->containskey(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getmax(int num)
    {
        Node* node = root;
        int maxnum = 0;
        for(int i = 31; i >= 0; i--) // Fix: Corrected loop
        {
            int bit = (num >> i) & 1; // Fix: Corrected bit extraction
            if(node->containskey(1-bit))
            {
               maxnum |= (1 << i);
               node = node->get(1-bit);
            }
            else
                node = node->get(bit);
        }
        return maxnum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        Trie ts;
        for(int i = 0; i < n; i++) // Fix: Corrected loop bounds
        {
            ts.insert(nums[i]);
        }
        for(int i = 0; i < n; i++) // Fix: Corrected loop bounds
        {
            int k = ts.getmax(nums[i]);
            ans = max(ans, k);
        }
        return ans;
    }
};

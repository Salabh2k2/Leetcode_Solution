class Bitset {
public:
    vector<int> bitset; // Stores the bits
    int n;              // Size of the bitset
    int on;             // Count of 1s
    int flipped;        // 0 for normal, 1 for flipped

    Bitset(int size) {
        bitset.resize(size, 0); // Initialize all bits to 0
        n = size;
        on = 0;
        flipped = 0; // Initially, not flipped
    }

    void fix(int idx) {
        if (flipped == 0) { // Normal state
            if (bitset[idx] == 0) {
                bitset[idx] = 1;
                on++;
            }
        } else { // Flipped state
            if (bitset[idx] == 1) {
                bitset[idx] = 0;
                on++;
            }
        }
    }

    void unfix(int idx) {
        if (flipped == 0) { // Normal state
            if (bitset[idx] == 1) {
                bitset[idx] = 0;
                on--;
            }
        } else { // Flipped state
            if (bitset[idx] == 0) {
                bitset[idx] = 1;
                on--;
            }
        }
    }

    void flip() {
        flipped = 1 - flipped; // Toggle the flipped state
        on = n - on;           // Adjust the count of 1s
    }

    bool all() {
        return on == n;
    }

    bool one() {
        return on > 0;
    }

    int count() {
        return on;
    }

    string toString() {
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (flipped == 0) {
                ans += (bitset[i] + '0');
            } else {
                ans += ((1 - bitset[i]) + '0');
            }
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

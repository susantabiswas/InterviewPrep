    /*
        Segment for min range queries.
        Given an array A of size N, there are two types of queries on this array.
     
        query(l, r): print the minimum in the sub-array
        update(x, y): arr[x] = y 
    */
    #include <bits/stdc++.h>
    using namespace std;
     
    // builds the segment tree
    int buildSegmentTree(int start, int end, int node, vector<int>& arr,
                            vector<int>& tree) {
        // when leaf node is reached
        if(start == end) {
            tree[node] = arr[start];
            return tree[node];
        }
        else {
            int mid = start + (end - start) / 2;
            int left = buildSegmentTree(start, mid, 2*node + 1, arr, tree);
            int right = buildSegmentTree(mid+1, end, 2*node + 2, arr, tree);
            
            // since each query involves finding min in range
            tree[node] = min(left, right);
            return tree[node];
        }
    }
     
    // for doing update operation
    void update(int x, int y, int start, int end, int node,
                vector<int>& arr, vector<int>& tree) {
        if(start == end) {
            arr[x] = y;
            tree[node] = y;
        }
        else {
            int mid = start + (end - start) / 2;
            // if it is in left subtree
            if(start <= x && x <= mid) {
                update(x, y, start, mid, 2*node + 1, arr, tree);
            }
            else {// it is in right subtree
                update(x, y, mid+1, end, 2*node + 2, arr, tree);
            }
            tree[node] = min(tree[2*node + 1], tree[2*node + 2]);
        }
    }
     
    // for doing query operation
    int query(int l, int r, int start, int end, int node,
                vector<int>& arr, vector<int>& tree) {
        // if given query is out of range
        if(r < start || l > end)
            return numeric_limits<int> ::  max();
        else if(l <= start && end <= r) { // if given range is within query range
            return tree[node];
        }
        else {  // if query range partially lie in the given range
            int mid = start + (end - start) / 2;
            int left = query(l, r, start, mid, 2*node + 1, arr, tree);
            int right = query(l, r, mid+1, end, 2*node + 2, arr, tree);
            
            return min(left, right);
        }
    }
     
    int main() {
        // Here input given is 1indexed
        int n, q;
        cin >> n >> q;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        char c;
        int a, b;
     
        // build the segment tree
        vector<int> tree(4*n, -1);
        buildSegmentTree(0, arr.size()-1, 0, arr, tree);
        
        for(int i = 0; i < q; i++) {
            cin >> c >> a >> b;
           
            if(c == 'q')
                cout << query(a-1, b-1, 0, arr.size()-1,0, arr, tree) << "\n";
            if(c == 'u')
                update(a-1, b, 0, arr.size()-1, 0, arr, tree);
        }
        return 0;
    }

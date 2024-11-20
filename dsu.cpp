#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> size;  // To store the size of each set


// Function to initialize the DSU structure for 'n' elements
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;  // Initially, each set has one element
}

// Find function with path compression

int find_set(int v) {
    if (v != parent[v]) {
        // Path compression: make the parent of v point directly to the root
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}

// Union function with union by size
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        // Union by size: attach the smaller tree under the larger tree
        if (size[a] < size[b]) {
            swap(a, b);  // Ensure 'a' is the larger root
        }
        parent[b] = a;  // Make 'a' the root of 'b'
        size[a] += size[b];  // Update the size of the new root
    }
}

int main() {

    int n, m;

    // Input number of elements (nodes)
    cout << "Enter number of elements: ";
    cin >> n;

    // Initialize DSU structure for n elements
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; ++i) {
        make_set(i);  // Make each element its own set
    }

    // Input number of union operations
    cout << "Enter number of union operations: ";
    cin >> m;

    cout << "Enter the union operations (a b) where you want to merge sets:\n";
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        union_sets(a, b);  // Perform union operation on a and b
    }

    // Input number of queries for checking if two elements are in the same set
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    cout << "Enter the queries (a b) to check if elements are in the same set:\n";
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        // Check if elements a and b are in the same set
        cout << "Are " << a << " and " << b << " in the same set? "
             << (find_set(a) == find_set(b) ? "Yes" : "No") << endl;
    }

    return 0;
}
/*input
Enter number of elements: 6
Enter number of union operations: 3
Enter the union operations (a b) where you want to merge sets:
0 1
2 3
4 5
Enter number of queries: 3
Enter the queries (a b) to check if elements are in the same set:
0 1
1 2
2 3

output
Are 0 and 1 in the same set? Yes
Are 1 and 2 in the same set? No
Are 2 and 3 in the same set? Yes
*/


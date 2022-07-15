<script>

    // JavaScript Program to show segment tree
    // operations like construction,
    // query and update
    class SegmentTree {
        /* Constructor to construct segment
        tree from given array. This constructor
        allocates memory for segment tree and calls
        constructSTUtil() to fill the allocated memory */
        constructor(arr, n) {
        // Allocate memory for segment tree
        // Height of segment tree
        var x = parseInt(Math.ceil(Math.log(n) / Math.log(2)));

        //Maximum size of segment tree
        var max_size = 2 * parseInt(Math.pow(2, x) - 1);

        this.st = new Array(max_size).fill(0); // Memory allocation

        this.constructSTUtil(arr, 0, n - 1, 0);
        }

        // A utility function to get the
        // middle index from corner indexes.
        getMid(s, e) {
        return parseInt(s + (e - s) / 2);
        }

        /* A recursive function to get
        the sum of values in given range
            of the array. The following
            are parameters for this function.

        st --> Pointer to segment tree
        si --> Index of current node in the
                segment tree. Initially
                    0 is passed as root is
                    always at index 0
        ss & se --> Starting and ending indexes
                        of the segment represented
                        by current node, i.e., st[si]
        qs & qe --> Starting and ending indexes of query range */
        getSumUtil(ss, se, qs, qe, si) {
        // If segment of this node is a part
        // of given range, then return
        // the sum of the segment
        if (qs <= ss && qe >= se) return this.st[si];

        // If segment of this node is
        // outside the given range
        if (se < qs || ss > qe) return 0;

        // If a part of this segment
        // overlaps with the given range
        var mid = this.getMid(ss, se);
        return (
            this.getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
            this.getSumUtil(mid + 1, se, qs, qe, 2 * si + 2)
        );
        }

        /* A recursive function to update
        the nodes which have the given
        index in their range. The following
        are parameters st, si, ss and se
        are same as getSumUtil() i --> index
        of the element to be updated. This
        index is in input array. diff --> Value
        to be added to all nodes which have i in range */
        updateValueUtil(ss, se, i, diff, si) {
        // Base Case: If the input index
        // lies outside the range of this segment
        if (i < ss || i > se) return;

        // If the input index is in range of
        // this node, then update the value
        // of the node and its children
        this.st[si] = this.st[si] + diff;
        if (se != ss) {
            var mid = this.getMid(ss, se);
            this.updateValueUtil(ss, mid, i, diff, 2 * si + 1);
            this.updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
        }
        }

        // The function to update a value
        // in input array and segment tree.
        // It uses updateValueUtil() to
        // update the value in segment tree
        updateValue(arr, n, i, new_val) {
        // Check for erroneous input index
        if (i < 0 || i > n - 1) {
            document.write("Invalid Input");
            return;
        }

        // Get the difference between
        // new value and old value
        var diff = new_val - arr[i];

        // Update the value in array
        arr[i] = new_val;

        // Update the values of nodes in segment tree
        this.updateValueUtil(0, n - 1, i, diff, 0);
        }

        // Return sum of elements in range
        // from index qs (query start) to
        // qe (query end). It mainly uses getSumUtil()
        getSum(n, qs, qe) {
        // Check for erroneous input values
        if (qs < 0 || qe > n - 1 || qs > qe) {
            document.write("Invalid Input");
            return -1;
        }
        return this.getSumUtil(0, n - 1, qs, qe, 0);
        }

        // A recursive function that constructs
        // Segment Tree for array[ss..se].
        // si is index of current node in segment tree st
        constructSTUtil(arr, ss, se, si) {
        // If there is one element in array,
        // store it in current node of
        // segment tree and return
        if (ss == se) {
            this.st[si] = arr[ss];
            return arr[ss];
        }

        // If there are more than one elements,
        // then recur for left and right subtrees
        // and store the sum of values in this node
        var mid = this.getMid(ss, se);
        this.st[si] =
            this.constructSTUtil(arr, ss, mid, si * 2 + 1) +
            this.constructSTUtil(arr, mid + 1, se, si * 2 + 2);
        return this.st[si];
        }
    }
    // Driver code
    var arr = [1, 3, 5, 7, 9, 11];
    var n = arr.length;
    var tree = new SegmentTree(arr, n);

    // Build segment tree from given array

    // Print sum of values in array from index 1 to 3
    document.write(
        "Sum of values in given range = "
        + tree.getSum(n, 1, 3) + "<br>"
    );

    // Update: set arr[1] = 10 and update
    // corresponding segment tree nodes
    tree.updateValue(arr, n, 1, 10);

    // Find sum after the value is updated
    document.write(
        "Updated sum of values in given range = " +
        tree.getSum(n, 1, 3) +
        "<br>"
    );
        
</script>

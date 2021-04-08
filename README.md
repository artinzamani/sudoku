# Sudoku
A simple console Sudoku solver.
The first input is the number of the given elements, which are already present in the table. Then, iterating from 1 to the number entered in the previous section, the user must enter the position and value of each cell, in this format: "Y X Z", where X and Y correspond to the X and Y element of the table (from 1 to 9), and Z is the value, all separated by spaces.
Sample input:
```
        > 10
        > 1 2 9
        > 1 5 2
        > 2 2 1
        > 2 3 3
        > 2 8 8
        > 3 1 5
        > 3 2 6
        > 3 4 4
        > 3 6 1
        > 3 8 9
```
which corresponds to this output:
```
        -------------------------
        | 4 9 7 | 3 2 8 | 1 5 6 |
        | 2 1 3 | 5 6 9 | 4 8 7 |
        | 5 6 8 | 4 7 1 | 2 9 3 |
        -------------------------
        | 1 2 4 | 6 3 5 | 8 7 9 |
        | 3 5 9 | 1 8 7 | 6 2 4 |
        | 7 8 6 | 2 9 4 | 3 1 5 |
        -------------------------
        | 6 3 1 | 7 5 2 | 9 4 8 |
        | 8 4 5 | 9 1 3 | 7 6 2 |
        | 9 7 2 | 8 4 6 | 5 3 1 |
        -------------------------
```

Please note that for given tables which do not have a unique answer, this program merely returns the first acceptable finished table that it stumbles upon.

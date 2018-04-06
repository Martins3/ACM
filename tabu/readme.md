# 运筹学作业

## Tuba

### Definitions
1. k-coloring `S`
2. evaluation function `f`
3. critical one move `<u, i, j>`
4. `neighborhood` 
5. a `incremental evaluation technique` to evaluate `neighborhood` quickly
6. a `special data structure` to get the move
7. `adjacent-color table` every vertex every color adjacent num
9. `incremental move value` when moves one vertex from one to another color, then number of conflicts, although it can be calculated easily, but the updating the table can be costly!

10. `tabu` means once **u** is performed, then at least k steps we will not perform the operation on it again

11. `tenure` 

12. `aspiration` If one move can override the best found solution found so far,
it is accepted even if it is in tabu status.

### Simple Versions of the code 
```
generate initial solution S
initialize the adjacent table
while(there exist improving steps)
    construct the neighborhood of S
    find all the delta for all the critical one move
    find the min delta
    update the table
```

### Tabu 
```
what only added is every time a move performed, add a tenure time stick to it !
```
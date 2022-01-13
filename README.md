# Car-Maze

C Program to find path from Start (S) to Destination (D)

- Takes input maze from user of max size 300
- Maze elements -> S (start), D (destination), # (block), . (legal move)
- Solution path marked by '+' symbol

<br>
Example input maze: <br>
S..# <br>
##.. <br>
##.. <br>
#D.. <br>

<br>
Solution: <br>

S++# <br>
##+. <br>
##+. <br>
#D+. <br>

Algorithm (Depth first search)
1. Start at S(x,y)
2. Check if x,y is destination (if True: end)
3. Check if x,y is legal
4. Mark as solution path
5. Recursively run steps 1-4 for all neighbors of x,y [(x,y+1), (x,y-1), (x+1,y), (x-1,y)] 

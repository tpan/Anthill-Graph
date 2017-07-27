# Anthill-Graph

This program interprets a map from the standard input and finds a viable path from the start to the end, only one "ant" may occupy
a given room at a time except the ##start and ##end.


Maps describe an ant farm in this format:
```
number_of_ants
the_rooms
the_links
```

An example of a map file:

```
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```
Usage will look something like this:
```
./lem_in < testmap
```

Output:
```
3
2 5 0
##start
0 1 2
##end
1 9 2
3 5 4
0-2
0-3
2-1
3-1
2-3
L1-3 L2-2
L1-1 L2-1 L3-3
L3-1
```

Which would be interpreted as:
Rooms: 2, 0, 1, 3
Connections: 0 to 2, 0 to 3, 2 to 1, 3 to 1 and so on.
Start: Room 0
End: Room 1

"Ant L1 moves to room 3, Ant L2 moves to room 2"

I also included a number of testing maps and a script called "Auto Lem in" that runs through them and has a nice verbose output.

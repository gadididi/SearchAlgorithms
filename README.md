# Search problems solver
A server that solves search problems. 

## General Description

This server can get from the client variuous Single source shortest path problems and solve them with the following algorithms:
1. A*
2. Best First Search
3. Breadth First Search (For none weighted graphs)
4. Depth First Search (For none weighted graphs)

## Collaborators

This program was developed by Gadi Didi and Ori Levy, CS students from Bar-Ilan university, Israel.



## Features

1. Connect to the server as client, and send search problems one by one, in a serialic order.

2. Connect multiple clients at once.


## Setup and execute


1. Download the source code from this git repository.

2. Complie the code:
    ```bash
    g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
    ```
3. Execute the code and connect your client. In the repository files you'll find 10 different searchable problems (Represented as a matrix).

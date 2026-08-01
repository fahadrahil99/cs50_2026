CS50x Problem Set 3: Elections (Plurality & Tideman)
This repository contains my C implementations for the Plurality and Tideman election algorithms.

Plurality
Plurality simulates a standard "first-past-the-post" election where each voter gets one vote, and the candidate with the most votes wins.

Key Takeaway: Working through this problem highlighted how C handles different data types under the hood. I learned the critical difference between comparing integers (which can be done directly with ==) and strings (which require memory-level comparison functions like strcmp because strings are essentially arrays of characters).

Implementation: I implemented a custom linear sort function to iterate through the candidates, organize the data, and reliably pull the winner based on the final vote tallies.

Tideman
Tideman (also known as the Ranked Pairs or Condorcet method) is a ranked-choice voting system that mathematically guarantees the election of the Condorcet winner if one exists.

Difficulty: Without a doubt, Tideman has been the hardest problem I have come across till now.

The lock Function: The lock_pairs function was particularly brutal. Figuring out how to lock in winning pairs without creating a cycle (which would mean no clear winner can be traced back to the source) was a major hurdle. The logic for cycle-detection required traversing the graph recursively, and I ultimately had to consult external references to fully wrap my head around it and get the function to pass all checks.

Compiling and Running
To compile either program, use make:

Bash
make plurality
make tideman
To run the programs, execute the compiled files and provide the names of the candidates as command-line arguments:

Bash
./plurality Alice Bob Charlie
./tideman Alice Bob Charlie
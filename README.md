# Leetcode practice problems

Below are all the [Easy](#easy), [Medium](#med) and [Hard](#hard) problems I've done for practice.

## Easy Problems <a name="easy"></a>
### Merge sorted Array (see `easy1.js`)
My initial intuitive solution had holes in it, I realise that my problem solving and critical thinking infact have holes in them, especially when I don't properly plan the solution out and write 2 lines of my thought process out, hoping it translates to a flawless code solution. Note to self: If the problem does not flow naturally or genuinely challenges you, WRITE YOUR STEPS DOWN and FORMULATE A SOLUTION. Even if it's not that challenging do it anyways! It's a good habit!

### Remove Element (see `easy2.js`)
Either my intuitive thinking is beginning to return to what it was before, or this question was on the easier side of easy problems. Either way, my intuitive solutions worked, although not completely refined. One of the community solutions filtered the array, and replaced the original array with the filtered array which to me sounds better than making a copy of the original array and replacing the values which are equal to the given value. Solution 3 is a refined version of my intuitive process, not using the array copy and instead only having an index tracker to replace values in the original array.

### Is subsequence (see `easy3.js`)
Intuitive solution again worked, but was not optimal - need to spend some more time thinking and find a more optimal solution. Though my intuitive solution works, I forgot proper usage of js functions and methods. Will need to revise js. Upon inspecting the more optimal solutions interms of time and space, they were very similar to mine, except they didn't create extra arrays. They instead had pointers to indexes of the strings that incremented if they found the matching character. This means I need to continue improving on my problem solving skills and efficiency in these problems. Take your time!!!

### Summary Ranges (`easy4.js`)
Intuitive solution was more thought out this time, I adapted my thoughts into an actual plan (observe below) and translated it into code (although I technically started writing the code first and got stuck). This is really good news! I'm adapting my thought process and problem solving ability. Even though these are still just easy leetcode problems this will set me up for the future!!! Solution 2 is a refactored version of my original solution, though it supposedly uses memory a lot poorer than my original solution. The third solution is one of the better solutions in terms of memory usage, but it performed averagely when I ran that solution on my machine.
```
example case: 0 1 2 4 5 7

initially:
 start = 0
 prev = 0
 end = ?

next:
 start = previous starting number if consecutive, current number if no longer consecutive
 prev = previous number
 end = ? if consecutive, prev if no longer consecutive

end:
 start = previous starting number if consecutive, current number if no longer consecutive
 prev = previous number
 end = this number if consecutive, this number if no longer consecutive
```

### Linked List (`easy5.js`)
Intuitive solution worked, problem was simple enough that my thought process didn't need to be written down. The only issue today was that I rushed it and didn't double check my code for simple mistakes. The only real issue with my solution was it's slow speed. A faster solution looked at the next element in the linked list, as well as the one after that, saving time and memory on the amount of iterations while still achieving the same answer.

### Maximum Depth of Binary Tree (`easy6.js`)
It's been a while since I've dealt with trees and graph theory so though my thought process for my initial solution was correct, implementation was quite rough since I haven't worked with these data structures in a while. For an easy problem like this, there was a one line solution, though for harder tree and graph questions they cannot be solved in one line (can't cheese it :/).

### Valid Parentheses (`easy7.js`)
My knowledge of basic data structures shone through here, utilising the correct data structure - a stack - here to solve the problem. Intuitive solution was correct, though implementation was a little verbose. Did not need to add a variable to check length, could simply check if the correct closing parenthesis followed the most recent open parenthesis. That misjudgement does serve as a reminder to always properly understand your own solution and recognise those steps; what data structures and algorithms do you intend to use (and keep those in mind!). If you don't do that, you risk over-complicating your code because you're mindlessly thinking of a solution which may cause you to overlook elements of your code.

### Average of Levels in Binary tree (`easy8.js`)
Similar to the previous binary tree problem that I did, I am greatly reminded that I need to practice more with data structures and algorithms. In this case, I seriously need to brush up on trees and graph theory if I have any chance of successfully doing the medium and hard problems later on. Intuitive solution was rushed, did not completely write down my solution which hindered my progress and allowed me to write a messy, verbose solution. 2nd solution is an optomised version of what I wanted to implement, effectively implementing a breadth-first search algorithm and a queue data strucutre. (Note: maybe have a look at COMP2521 notes again?)

### Minimum Absolute Difference in BST (`easy9.js`)
Unfortunately I read the question wrong and created an incorrect solution. I thus had to restart and think of another solution which worked. Intuitive solution could have been more refined, could have realised that if I traversed the tree in order (using depth-first) it would have been much more efficient instead of purely finding all values in the tree, sorting and *then* finding the smallest interval. More practice and critical thinking needed. Spending a little extra time on problems never hurts!!

### Converted Sorted Array to Binary Search Tree (`easy10.js`)
Another binary tree problem, my thought process was correct - hard to go wrong with simply implementing a bst - but again my implementation let me down. Didn't properly implement the creation of a bst and found errors initially of creating unbalanced trees. The problem here was that I wasn't setting the middle of the sub arrays to be the parent node of the subtree and so each subtree had a chance of being unbalanced. Goes to show I need more practice and time spent on these fundamentals.

### Search Insert Position (`easy11.js`)
Problem solved with relative ease, simple binary search (two pointers/indexes at opposite ends of the array) implementation. Saw a solution that completely disregarded the idea of the problem; though incredibly fast, it is impractical and not what the question aims to test (i think).

### Add Binary (`easy12.js`)
Solution was simple convert binary to integer, add then convert back into binary. This was made much easier in js because of the parseInt/BigInt and toString methods. I did fail at first because I forgot about precision and the fact that the binary numbers could extend the length of normal integers. It was a simple fix. Easy problem today!

### Plus One (`easy13.js`)
Solution was simple, other solutions I found on leetcode were not clean enough so my own was good enough. Simple problem today.

### Climbing Stairs (`easy14.js`)
Couldn't figure this one out, the clue I was given was 1D Dynamic Programming, perhaps using memoization but I couldn't figure it out. A posted solution used fibonacci, which I don't think fully encapsultes what this problem is trying to train and assess. EDIT: Added solutions that properly utilise memoization.

### Remove Duplicated from Sorted Array (`easy15.js`)
Overthought the problem here today, I thought if I just made it a set and then used that then the problem be solved most efficiently. However, most of the faster solutions used the more primitive idea of a for loop and changing the values of the array. Hey, sometimes simple is best! Don't need to overcomplicate the solution using extra data structures and algorithms.

### Same Tree (`easy16.js`)
The problem itself was on the simpler side, but it was another tree problem so it required that specific thought process (and by that I mean how do I iterate through the tree efficiently). Worked out in the end, but my solution wasn't as clean as it could have been (evident with the 2nd solution)

### Roman to Integer (`easy17.js`)
This was a problem that was harder to write an efficient solution in terms of both time and space. My original solution was fast, but wasn't the most space efficient one. For a more optimal solution, observe Solution 2
### Kth Largest Element in Array (`medium7.js`)
Couldn't figure out how to do this with heaps and a priority queue, completed it via a simple sort and index solution. Solution 2 is an example of how to solve the problem using a heap and a priority queue.

### Majority Element (`easy18.js`)
Misread the challenge prompt, was trying to think of a O(1) time solution for the longest time hahaha. My intuitive solution worked, but I couldn't figure out how to completely optimise it for a while beacuse I kept thinking of using multiple variables for the majority value, and the count of each variable. However, given the question conditions, I was actually overthinking the problem and so all I had to check was the number which occured more than n / 2 times (because it was guaranteed). Again a reminder to read the questions carefully (two reminders in one!)

### Single Number (`easy19.js`)
My initial solution did not utilise bit manipulation at all, which was the whole premise of the problem. The second solution addresses that in an efficient and interesting manner. Might need to read up on my binary knowledge and how I can apply that to problems such as these.

### Max Profit (`easy20.js`/`easy20.ts`)
This problem was simple, I was able to reduce the problem to finding the greatest difference between two numbers and returning that difference. All the other solutions that I saw weren't as clean or logical as my own so I was happy with just my attempt. That was in js, for some reason that same solution in ts was slower (I'm assuming it was because of the type safety since I didn't typecast my variables and the engine took longer to auto assign.).

### Length of Last Word (`easy21.js`)
Simple string to array manipulation and collecting information. Second solution is neater than the first one but ultimately does the same thing. Nice and simple problem today :)

### Longest Common Prefix (`easy22.js`)
Took a little longer to solve because I was thinking about the solution and spent some time writing down my thought process and how to implement. Not sure what's so different about my answers and the fastest performing ones, they were almost identical yet mine was drastically slower. Good solving today :))

### Find the Index of the First Occurence in a String (`easy23.js`)
My intuitive solution worked, but was on the slower side of the majority of posted solutions. The 2nd solution was optimal, using the double pointer method to solve the problem slightly faster, though both solutions have a worst-case time complexity of O((n - m + 1) * m).

### Isomorphic Strings (`easy24.js`)
My intuitive solution was a little messy and utilised some js Object methods to check if my dictionary had certain keys and values. The second solution implemented two hashmaps instead of my one and it made the solution more readable and efficient. The use of two hashmaps instead of one slipped past my mind, silly mistake leading me to not create an optimal solution. But hey it was a solution nonetheless!

### Word Pattern (`easy25.js`)
Similar problem to the isomorphic strings one, so my intuitive solution worked quite well here. Good problem, no problems here.

### Valid Anagram(`easy26.js`)
This was a ambiguous question in the sense that there are hundred of ways to solve this, some more efficient or creative than others. The way I chose to do it was to create arrays of the letters of both strings and compare the arrays.

### Happy Number (`easy27.js`)
This felt more like a math challenge to see if I could find any patterns would help me find a one liner solution. Didn't find any patterns so I had to instead split the number up and operate on it like that until we could determine if it was a happy number or not.

### Contains Duplicate II (`easy28.js`)
My initial solution worked, but it was too slow for larger cases and so I had to refactor so it was more efficient. I didn't realise me using the indexOf() method within the for loop made my function O(n^2). Using a map was much more efficient (STOP FORGETTING ABOUT USING MAPS).

______________________________________________________________________________________________________________________________________________________________________________

## Medium Problems <a name="med"></a>
### Maximum Score From Removing Stones (see `medium1.js`)
After a long uni term of design principle study and more refactoring than critical thinking, in the direct problem solving sense, this problem was a good refresher for me, helping highlight that I have neglected such critical thinking for a long enough time that standard problems such as this one proved difficult again.

### Clone Graph (`medium2.js`)
Though my thought process was correct, my implementation wasn't. Due to a lack of understanding of more complex data structures I started off using more basic structures which left holes in my implementation; an example of this was my implementation of the visited nodes array which started off as an array, then becoming a set and finally a map which accurately kept track of visited nodes and a copy of the respective nodes. Traversing graphs and trees are becoming easier to implement, showing that the practice is paying off! Can't stop now!

### Snakes and Ladders (`medium3.js`)
Today was the first failure in a while. Though my thought process was right and I tried to implement the correct algorithm (BFS), my lack of a proper understanding of how to implement BFS caused the implementation to fail. Not only that, but I overthought the solution as well, writing multiple helper functions which didn't end up helping since I failed the question today anyways. The takeaways from today are to read up on data structures and algorithms (and keep practicing them!) and if you start to overthink and over compensate for failing code, step back, clear your head and rethink your solution.

### Implement Trie (Prefix Tree) (`medium4.js`)
Forgot what a trie data structure looked like, had to google and stumbled across a near-exact implementation of this problem, so definitely lucked out (googled a little too hard haha). Solution 2 is a less general-purpose solution, tailored to the premise of the question and isn't too applicable outside of that problem so I like my implementation better. Good reminder to revisit data structures and algorithms (keep it up!).

### Letter Combinations of a Phone Number (`medium5.js`)
Below is how the backtracking algorithm for this problem works (for depth 3). Didn't really have a clue with this one, I've always struggled with back-tracking, will need to keep on practicing with this algorithm. It seems very self-explanatory after looking at the solution. It's a simple recursive function :// The main idea behind backtracking is establishing a "checkpoint" which is done with each level of recursion; Once you've reached the end of the recursive loop, you back out to the nearest checkpoint and go a different way - like making a trail of where you went and following it back once you hit a dead end (you BACKTRACK, hence the name haha). 
```
Initial call: generateCombinations(0, '')
|
|-- First recursive call: generateCombinations(1, 'a')   (digit "2")
|   |
|   |-- Second recursive call: generateCombinations(2, 'ad')   (digit "3")
|   |   |
|   |   |-- Third recursive call: generateCombinations(3, 'add')   (reached end, add to result) (digit "3")
|   |   |
|   |   |-- Third recursive call: generateCombinations(3, 'ade')   (reached end, add to result)
|   |   |
|   |   |-- Third recursive call: generateCombinations(3, 'adf')   (reached end, add to result)
|   |
|   |-- Second recursive call: generateCombinations(2, 'ae')   (digit "3")
|   |   |
|   |   |-- Third recursive call: generateCombinations(3, 'aed')   (reached end, add to result) (digit "3")
|   |   |
|   |   |-- Third recursive call: generateCombinations(3, 'aee')   (reached end, add to result)
|   |   |
|   |   |-- Third recursive call: generateCombinations(3, 'aef')   (reached end, add to result)
|   |
|   |-- Second recursive call: generateCombinations(2, 'af')   (digit "3")
|       |
|       |-- Third recursive call: generateCombinations(3, 'afd')   (reached end, add to result) (digit "3")
|       |
|       |-- Third recursive call: generateCombinations(3, 'afe')   (reached end, add to result)
|       |
|       |-- Third recursive call: generateCombinations(3, 'aff')   (reached end, add to result)
|
|-- First recursive call: generateCombinations(1, 'b')   (digit "2")
    |
    |-- Second recursive call: generateCombinations(2, 'bd')   (digit "3")
    |   |
    |   |-- Third recursive call: generateCombinations(3, 'bdd')   (reached end, add to result) (digit "3")
    |   |
    |   |-- Third recursive call: generateCombinations(3, 'bde')   (reached end, add to result)
    |   |
    |   |-- Third recursive call: generateCombinations(3, 'bdf')   (reached end, add to result)
    |
    |-- Second recursive call: generateCombinations(2, 'be')   (digit "3")
    |   |
    |   |-- Third recursive call: generateCombinations(3, 'bed')   (reached end, add to result) (digit "3")
    |   |
    |   |-- Third recursive call: generateCombinations(3, 'bee')   (reached end, add to result)
    |   |
    |   |-- Third recursive call: generateCombinations(3, 'bef')   (reached end, add to result)
    |
    |-- Second recursive call: generateCombinations(2, 'bf')   (digit "3")
        |
        |-- Third recursive call: generateCombinations(3, 'bfd')   (reached end, add to result) (digit "3")
        |
        |-- Third recursive call: generateCombinations(3, 'bfe')   (reached end, add to result)
        |
        |-- Third recursive call: generateCombinations(3, 'bff')   (reached end, add to result)
```

### Maximum Subarray (`medium6.js`)
This was a problem about Kadane's algorithm, something which I had no idea about. Had to google it and figure it out from there, so I didn't tehcnically  figure that out on my own. I feel as though I made up for it with an extension activity, changing the the return value from the largest sum to the subarray that contains the largest sum. Even though I had inspirtaion for my implementation, it still was not incredibly efficient, in time or in space. The 2nd solution is slightly more time efficient and increasingly space efficient because I don't initialise n variables and rather intialise the index once and alter that. I've added an extra solution that uses memoization, just useful for knowing what memoization is.

### House Robbing (`medium8.js`)
With this problem, my intuitive solution wasn't aligned with the way the problem was meant to be solved. With a lot of these dynamic programming problems I seem to neglect the fact that they are dynamic solutions and try use slow, recursive solutions that either take too long or use too much memory for larger cases. I think this happens because I tunnelvision on a certain aspect of the problem and forget about the bigger picture so I need to start thinking holistically about solving a problem, not forgetting about certain important parts of the problem.

### Triangle (`medium9.js`)
I faced similar challenges to the previous problem, it is obvious that the lessons haven't exactly been cemented in my mind which is fine for now, but I need to get it in my thick skull that I need to approach the problem with an open mind, and do my best not to tunnelvision. If you're doing a problem about dynamic programming, try think of a dynamic solution!!! Yes you can probably use a recursive tree traversal that is part of your bread and butter, but it might be slow and will need to adapted to the problem at hand!!! Also uploads are patchy, don't always have access to github due to being overseas. 

### Minimum Path Sum (`medium10.js`)
Still struggling a bit with dynamic programming and memoization, specifically these "minimum path" problems. Will need to use more practice on it. My original approach was to have an array of the possible results, but there were bugs with the way I traversed the grid and calculated the end results. The more effective solution adapted to the question and solved it efficiently, constructing all the necessary foundations to solve the problem and then effectively using their implemented memoization table.
Adding medium 11 - 30

### Integer to Roman (`medium31.py`)
Took a linear time complexity approach here, iterated through the digits of the number to create the roman numeral. Other solutions stored more values in their maps of integers to roman numerals which made the bulk of their code, iterating through the number to translate the integer, cleaner.

### Remove Nth Node from End of List (`medium32.py`)
Initially misread the question as remove Nth node from the list, so I had to decrement my counter, instead of incrementing it, and iterate through the linked list an extra time to find the length of the linked list. Sample solutions used a slow and fast pointer to keep track of current and previous nodes in the list where I used current and previous variables.

### Add Two Numbers (`medium33.py`)
Another relatively simple problem, was debating whether to traverse the linked list and find the sum in one loop, or retrieve the numbers from each linked list and create a new linked list using the found sum. Both solutions work, I think my solution is a little more readable and easier to implement.
______________________________________________________________________________________________________________________________________________________________________________


## Hard Problems <a name="hard"></a>

### Candy (`hard1.py`)
First hard problem!!! The intuition to this problem was not incredibly hard, though the solution took a bit of time to figure out. I spent a lot of time thinking about what data structures would be best to use with this question when I was ignoring the fact that everything I needed was in the supplied array. Establishing every child to start with 1 candy was the first step, then it was to iterate through the array once forwards to track all the left neighbours, and once backwards to update all the right neighbours. I had thought of using two or three pointer methods, but those would have required methods of updating the children after each iteration and would have been incredibly inefficient. This was a half success, had to look at solutions to finalise the problem.

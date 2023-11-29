# Leetcode practice problems

### Maximum Score From Removing Stones: Medium problem (see `medium1.js`)
After a long uni term of design principle study and more refactoring than critical thinking, in the direct problem solving sense, this problem was a good refresher for me, helping highlight that I have neglected such critical thinking for a long enough time that standard problems such as this one proved difficult again.

### Merge sorted Array: Easy problem (see `easy1.js`)
My initial intuitive solution had holes in it, I realise that my problem solving and critical thinking infact have holes in them, especially when I don't properly plan the solution out and write 2 lines of my thought process out, hoping it translates to a flawless code solution. Note to self: If the problem does not flow naturally or genuinely challenges you, WRITE YOUR STEPS DOWN and FORMULATE A SOLUTION. Even if it's not that challenging do it anyways! It's a good habit!

### Remove Element: Easy problem (see `easy2.js`)
Either my intuitive thinking is beginning to return to what it was before, or this question was on the easier side of easy problems. Either way, my intuitive solutions worked, although not completely refined. One of the community solutions filtered the array, and replaced the original array with the filtered array which to me sounds better than making a copy of the original array and replacing the values which are equal to the given value. Solution 3 is a refined version of my intuitive process, not using the array copy and instead only having an index tracker to replace values in the original array.

### Is subsequence: Easy problem (see `easy3.js`)
Intuitive solution again worked, but was not optimal - need to spend some more time thinking and find a more optimal solution. Though my intuitive solution works, I forgot proper usage of js functions and methods. Will need to revise js. Upon inspecting the more optimal solutions interms of time and space, they were very similar to mine, except they didn't create extra arrays. They instead had pointers to indexes of the strings that incremented if they found the matching character. This means I need to continue improving on my problem solving skills and efficiency in these problems. Take your time!!!

### Summary Ranges: Easy problem (`easy4.js`)
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

### Linked List: Easy problem (`easy5.js`)
Intuitive solution worked, problem was simple enough that my thought process didn't need to be written down. The only issue today was that I rushed it and didn't double check my code for simple mistakes. The only real issue with my solution was it's slow speed. A faster solution looked at the next element in the linked list, as well as the one after that, saving time and memory on the amount of iterations while still achieving the same answer.

### Maximum Depth of Binary Tree (`easy6.js`)
It's been a while since I've dealt with trees and graph theory so though my thought process for my initial solution was correct, implementation was quite rough since I haven't worked with these data structures in a while. For an easy problem like this, there was a one line solution, though for harder tree and graph questions they cannot be solved in one line (can't cheese it :/).

### Valid Parentheses (`easy7.js`)
My knowledge of basic data structures shone through here, utilising the correct data structure - a stack - here to solve the problem. Intuitive solution was correct, though implementation was a little verbose. Did not need to add a variable to check length, could simply check if the correct closing parenthesis followed the most recent open parenthesis. That misjudgement does serve as a reminder to always properly understand your own solution and recognise those steps; what data structures and algorithms do you intend to use (and keep those in mind!). If you don't do that, you risk over-complicating your code because you're mindlessly thinking of a solution which may cause you to overlook elements of your code.

### Average of Levels in Binary tree (`easy8.js`)
Similar to the previous binary tree problem that I did, I am greatly reminded that I need to practice more with data structures and algorithms. In this case, I seriously need to brush up on trees and graph theory if I have any chance of successfully doing the medium and hard problems later on. Intuitive solution was rushed, did not completely write down my solution which hindered my progress and allowed me to write a messy, verbose solution. 2nd solution is an optomised version of what I wanted to implement, effectively implementing a breadth-first search algorithm and a queue data strucutre. (Note: maybe have a look at COMP2521 notes again?)

### Minimum Absolute Difference in BST (`easy9.js`)
Unfortunately I read the question wrong and created an incorrect solution. I thus had to restart and think of another solution which worked. Intuitive solution could have been more refined, could have realised that if I traversed the tree in order (using depth-first) it would have been much more efficient instead of purely finding all values in the tree, sorting and *then* finding the smallest interval. More practice and critical thinking needed. Spending a little extra time on problems never hurts!!

### Clone Graph (`medium2.js`)
Though my thought process was correct, my implementation wasn't. Due to a lack of understanding of more complex data structures I started off using more basic structures which left holes in my implementation; an example of this was my implementation of the visited nodes array which started off as an array, then becoming a set and finally a map which accurately kept track of visited nodes and a copy of the respective nodes. Traversing graphs and trees are becoming easier to implement, showing that the practice is paying off! Can't stop now!

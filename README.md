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


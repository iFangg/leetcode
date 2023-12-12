// Solution 1
int removeDuplicates(int* nums, int numsSize) {
    int counter = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[counter] = nums[i];
            counter++;
        }
    }

    return counter;
}

// Solution 2
int removeDuplicates(int* nums, int numsSize) {
    int offset = 0;
    int last = nums[0];

    for (int i = 1; i < numsSize; i++) {
        nums[i - offset] = nums[i];

        if (nums[i] == last) {
            offset++;
        }

        last = nums[i];
    }

    return numsSize - offset;
}

// Solution 1
uint32_t reverseBits(uint32_t n) {
    uint32_t reverseN = 0;
    for (int i = 0; i < 32; i++) {
        // shift left for first 16, shift right for next 16
        reverseN |= ((n >> i) & 1) << (31 - i);
    }

    return reverseN;
}


// Solution 2
uint32_t reverseBits(uint32_t n) {
    n =  (n & 0x0000ffff) << 16 | (n & 0xffff0000) >> 16 ; //reverse 16 bits 
    n =  (n &  0x00ff00ff) << 8  | (n & 0xff00ff00) >> 8 ; //reverse 8 bits 
    n =  (n & 0x0f0f0f0f ) << 4  | (n & 0xf0f0f0f0) >> 4 ;  //reverse 4 bits 
    n =   (n & 0x33333333) << 2   | (n  &  0xcccccccc) >> 2 ; // reverse 2 bits 
    n =   (n & 0x55555555) << 1 | (n  &  0xaaaaaaaa) >> 1 ; //reverse 1 bits 
    
    return n;
}

# Solution 1
class Solution:
    def intToRoman(self, num: int) -> str:
        translate = {
            1: 'I',
            5: 'V',
            10: 'X',
            50: 'L',
            100: 'C',
            500: 'D',
            1000: 'M',
        }

        roman = ""
        tens = 10 ** (len(str(num)) - 1)
        prev = num
        while tens > 0:
            digit = translate[tens]
            n = prev // tens
            # print(f"{tens} - {digit}, * {n}")
            if n == 4: roman += digit + translate[tens * 5] 
            elif n == 5: roman += translate[tens * 5]
            elif n == 9: roman += digit + translate[tens * 10]
            else:
                roman += digit * n if n < 4 else translate[tens * 5] + digit * (n % 5)
            
            prev -= n * tens
            tens = tens // 10
        
        return roman


#  Solution 2
    def intToRoman(self, num: int) -> str:
        Roman = ""
        storeIntRoman = [[1000, "M"], [900, "CM"], [500, "D"], [400, "CD"], [100, "C"], [90, "XC"], [50, "L"], [40, "XL"], [10, "X"], [9, "IX"], [5, "V"], [4, "IV"], [1, "I"]]
        for i in range(len(storeIntRoman)):
            while num >= storeIntRoman[i][0]:
                Roman += storeIntRoman[i][1]
                num -= storeIntRoman[i][0]
        return Roman

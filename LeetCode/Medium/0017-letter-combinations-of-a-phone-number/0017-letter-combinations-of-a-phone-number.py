def dfs(digits,index, numbers_char, possible_string,answers):
    if(index == len(digits)):
        answers.append(possible_string)
        return 
    for char in numbers_char[digits[index]]:
        dfs(digits, index+1, numbers_char, possible_string+char, answers)

    return answers
    

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        numbers_char = {
            '0': [' '],
            '1': [],
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
        }

        answers = []
        return dfs(digits, 0,numbers_char, "",answers)
        
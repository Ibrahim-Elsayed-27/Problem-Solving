class RandomizedSet:

    def __init__(self):

        self.elements = []
        self.index_dict = {}
        
    def insert(self, val: int) -> bool:
        if val in self.index_dict:
            return False

        self.index_dict[val] = len(self.elements)
        self.elements.append(val)
        return True

    def remove(self, val: int) -> bool:
        if not(val in self.index_dict):
            return False
        last_element = self.elements[-1]
        target_index = self.index_dict[val]
        self.index_dict[last_element] = target_index
        self.elements[target_index] = last_element
        self.elements.pop()
        self.index_dict.pop(val)
        return True


    def getRandom(self) -> int:
        return random.choice(self.elements)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        '''
        Idea 1 : anagram -> looks the same after sorting -> O(m*n*logn)
        Idea 2 : hash map -> key = number of each characters in the string e.g. "eat" -> 1a1e1t
        '''
        ans = defaultdict(list) # dictionary : key -> value

        for s in strs :
            # get hash key
            key = [0] *26 # create a list with 26 elements, all initialized to 0
            for c in s :
                key[ord(c) - ord("a")] += 1 # ord() : get ASCII value

            # store to hash map
            ans[tuple(key)].append(s)

        return ans.values()
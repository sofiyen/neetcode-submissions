class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        '''
        Idea : max-heap -> key = frequency, value = number
        '''
        # get frequency
        freq = defaultdict(int) # store frequency of numbers
        for number in nums:
            freq[number] -= 1
        
        # create heap
        heap = []
        for value,key in freq.items(): 
            heapq.heappush(heap, tuple([key,value]))
        
        ans = []
        for i in range(k):
            key, value = heapq.heappop(heap)
            ans += [value]

        return ans
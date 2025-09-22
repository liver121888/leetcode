class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = defaultdict(list)
        freq = {}
        curr_max_freq = 0
        curr_max_freq_cnt = 0

        # record curr_max_freq

        # if num_freq is > curr_max_freq
        # replace curr_max_freq
        # reset curr_max_freq_cnt

        # if num_freq is == curr_max_freq
        # curr_max_freq_cnt += 1

        # if num_freq is < curr_max_freq
        # pass

        for num in nums:
            
            if num in freq:
                freq[num] += 1
            else:
                freq.update({num: 1})
            num_freq = freq[num]
            if num_freq == curr_max_freq:
                curr_max_freq_cnt += 1
            elif num_freq > curr_max_freq:
                curr_max_freq = num_freq
                curr_max_freq_cnt = 1


        # 1 2 2 3 1 4
        # curr_max_freq = 1
        # curr_max_freq_cnt = 1
        # 2 2 3 1 4
        # curr_max_freq_cnt = 2
        # 2 3 1 4
        # curr_max_freq = 2
        # curr_max_freq_cnt = 1
        # 3 1 4
        # 1 4
        # curr_max_freq = 2
        # curr_max_freq_cnt = 2
        # 4
        # end
        # 2 * 2 = 4

        return curr_max_freq_cnt * curr_max_freq

        
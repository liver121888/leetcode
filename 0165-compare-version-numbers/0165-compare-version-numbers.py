class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:

        v1 = version1.split('.')
        v2 = version2.split('.')

        v1_array = []
        v2_array = []

        for num_str in v1:
            v1_array.append(int(num_str.strip()))

        for num_str in v2:
            v2_array.append(int(num_str.strip()))

        # print(v1_array)
        # print(v2_array)

        maxLen = max(len(v1_array), len(v2_array))

        if len(v1_array) < maxLen:
           v1_array = v1_array + [0] * (maxLen - len(v1_array))

        if len(v2_array) < maxLen:
           v2_array = v2_array + [0] * (maxLen - len(v2_array))

        for n1, n2 in zip(v1_array, v2_array):
            if n1 > n2:
                return 1
            elif n1 < n2:
                return -1
            else:
                continue

        return 0
        

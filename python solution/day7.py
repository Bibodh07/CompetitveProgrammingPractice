


def twoSum(arr, k):
    hMap = {}
    for i in range(len(arr)):
        if (k - arr[i]) in hMap:
            return [hMap[k - arr[i]], i]
        hMap[arr[i]] = i
    return []


def validAnagram(s, t):
    seen = {}

    if(len(s) != len(t)):
        return False

    for i in range(len(s)):
        seen[s[i]] = seen.get(s[i], 0) + 1


    for j in range(len(t)):

        if t[j] not in seen:
            return False

        seen[t[j]] -= 1


    for k in seen.values():
        if(k != 0):
            return False

    return True





def validPalindrom(s):



    l = 0
    r = len(s) -1 

    s = s.lower()

    while l <= r :
        if not s[r].isalnum():
            r-=1
            continue
        if not s[l].isalnum():
            l+=1
            continue
        if s[l].lower() != s[r].lower():
            return False
        l += 1
        r -= 1




    return True

print(validPalindrom('racecar', 'racecar'))

def longestSubString(s):
    best_length = 0
    seen = set()
    l = 0

    for r in range(len(s)):
        while s[r] in seen:
            seen.remove(s[l])
            l += 1
        seen.add(s[r])
        best_length = max(best_length, r - l + 1)

    return best_length

   

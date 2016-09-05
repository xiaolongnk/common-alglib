class Solution(object):

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        ns = "#"+"#".join(list(s))+"#"
        max = 1
        pos = 0
        mlen = len(ns)
        for i in range(0,mlen):
            currentMax = 1;
            for j in range(0,i):
                l = i - j - 1
                r = i + 1 + j
                if l < 0 or r >= mlen:
                    break;
                if ns[l] == ns[r]:
                    currentMax+=2
                else:
                    break;
            currentMax = (currentMax - 1) /2
            if currentMax >= max:
                max = currentMax
                pos = i
        return "".join(ns[pos - max: pos + max + 1].split("#"))
    

    

def run():
    ns = Solution()
    st = "jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel"
    print ns.longestPalindrome(st)

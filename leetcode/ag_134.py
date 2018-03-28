class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        gas_needed, gas_left,start = 0,0,0
        for i, (g,c) in enumerate(zip(gas, cost)):
            gas_left += g - c
            if gas_left < 0:
                gas_needed -=  gas_left
                start = i + 1
                gas_left = 0
        
        return start if gas_left >= gas_needed else -1

def run():
    pass

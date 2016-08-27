class Solution(object):

    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        ans = []
        self.solve( num  , target , ans , 0 ,"" ,0 ,0)
        return ans

    def solve(self , num , target , retList , pos , path , current , prev ):
        if len(num) == pos:
            if current == target:
                retList.append(path)
                return
        
        for i in range(pos , len(num)):
            if i != pos and num[pos] == '0':
                break;
            curstr = num[pos:i+1]
            currentval = int(curstr)
            if pos == 0:
                self.solve(num , target , retList , i+1 , path + curstr , current + currentval , currentval)
            else:
                self.solve(num , target , retList , i+1 , path + '+' + curstr , current + currentval , currentval)
                self.solve(num , target , retList , i+1 , path + '-' + curstr , current - currentval , -currentval)
                self.solve(num , target , retList , i+1 , path + '*' + curstr , current - prev + prev * currentval , prev * currentval)

if __name__=='__main__':
    sn = Solution()
    num = "105"
    target = 5
    print sn.addOperators(num , target)

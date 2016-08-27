import collections

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.ldict = collections.OrderedDict()
        

    def get(self, key):
        """
        :rtype: int
        """
        try:
            value = self.ldict[key]
            del self.ldict[key]
            self.ldict[key] = value
            return value
        except:
            return -1

        

    def set(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        print self.capacity
        print self.ldict
        try:
            del self.ldict[key]
            self.ldict[key] = value
        except:
            if len(self.ldict) == self.capacity:
                self.ldict.popitem(last=False)
            self.ldict[key] = value

    def mprint(self):
        print self.ldict

if __name__=='__main__':
    lru = LRUCache(3)
    lru.set(1,1)
    lru.set(2,2)
    lru.set(3,3)
    lru.set(4,4)
    lru.set(5,5)
    lru.set(3,3)
    lru.set(6,6)
    lru.mprint()
    pass

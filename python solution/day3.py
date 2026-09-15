#implementing my own iterator 




class goalCounter():
    def __init__(self, limit, start = 0):
        self.current = start
        self.limit = limit

    def __iter__(self):
        return self #iterator object

    def __next__(self):
        if(self.current > self.limit):
            raise StopIteration

        value = self.current
        self.current += 1

        return value
        

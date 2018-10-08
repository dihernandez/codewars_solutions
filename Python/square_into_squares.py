class HelperFunctions:
    def __init__(self):
        pass

    #generates a list of prime numbers less than n
    @staticmethod
    def generatePrimes(n):
        myprimes = []
        visisted =[]
        not_primes = []
        current_num = 2
        if n < 2:
            return []
        else:
            while(current_num <= n):
                for v in visisted:
                    if current_num%v == 0 and current_num not in not_primes:
                        not_primes.append(current_num)
                if current_num not in not_primes:
                    myprimes.append(current_num)
                visisted.append(current_num)
                current_num += 1
            return myprimes


class Solver:
    def __init__(self, n):
        self.n = n
        self.nsquare = n**2 
        self.solution = []
        self.primes = HelperFunctions.generatePrimes(n)

    def sumsToNsquare(self):
        return sum([number**2 for number in self.solution]) == self.nsquare

    def isAllSquares(self):
        return sum([not isSquare(factor) for factor in self.solution]) == 0 #True = 1 False = 0

    def isValid(self):        
	    return solution[0] == solution[-1] if (sumsToNsquare(self) and isAllSquares(self)) else False 
  
    def isSquare(self, factor):
    	primes = generatePrimes(factor)
        if n in primes:
        	return False
        else:
            while True:
                pass 

    def solve(self):
        while counter < self.n:
            pass
    def getResult(self):
        solve()
        return self.solution if isValid() else None
        
def decompose(n):
    mySolver = Solver(n)
    return mySolver.getResult()

#decompose(5)
myTestSolver = Solver(5)
myTestSolver.solution = [3,4]
assert myTestSolver.sumsToNsquare() == True

        
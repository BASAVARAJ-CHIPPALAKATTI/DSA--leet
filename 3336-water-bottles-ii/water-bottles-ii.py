class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        drunk_bottles=numBottles
        while numBottles >= numExchange:
            numBottles-=numExchange
            numBottles+=1
            drunk_bottles+=1
            numExchange+=1
        return drunk_bottles
        
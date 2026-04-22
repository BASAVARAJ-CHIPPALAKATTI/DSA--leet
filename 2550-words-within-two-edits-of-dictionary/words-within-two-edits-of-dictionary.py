class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans=[]
        for i in range(len(queries)):
            for j in range(len(dictionary)):
                count=0
                for k in range(len(queries[0])):
                    if queries[i][k]!=dictionary[j][k]:
                        count+=1
                        if count >2:
                            break
                if count <=2:
                    ans.append(queries[i])
                    break
        return ans
                

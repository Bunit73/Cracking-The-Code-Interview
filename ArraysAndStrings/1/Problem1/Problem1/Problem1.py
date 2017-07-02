def BruteForce(word):
    if len(word) == 0:
        return False
    for x in range(len(word)):
        for y in word[x+1:]:
            if word[x] == y:
                return False
    return True        

if __name__ == "__main__":
    word = "ABACA"
    if BruteForce(word):
        print("Brute Force: No Dups")
    else:
        print("Brute Force: Dups")
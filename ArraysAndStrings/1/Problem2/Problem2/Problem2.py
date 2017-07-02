def sortCheck(strA,strB):
    if len(strA) != len(strB):
        return False

    strA = ''.join(sorted(strA))
    strB = ''.join(sorted(strB))

    for x in range(len(strA)):
        if strA[x] != strB[x]:
            return False

    return True

if __name__ == "__main__":
    wordA = "aad"
    wordB = "god"
    if(sortCheck(wordA,wordB)):
        print("Word A is a perm of B")
    else:
        print("Word A is NOT a perm of B")
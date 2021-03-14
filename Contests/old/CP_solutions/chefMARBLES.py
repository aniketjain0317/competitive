# your code goes here
from sys import stdin, stdout


def main():
    t = int(stdin.readline())
    arrN = [0] * t
    arrK = [0] * t
    for i in range(t):
        arrN[i], arrK[i] = stdin.readline().split()
        arrN[i]=int(arrN[i])
        arrK[i]=int(arrK[i])
    x = int(max(arrN))
    fact=[1]
    for i in range(x + 1):
        fact.append(fact[i] * (i + 1))
    for i in range(t):
        n = arrN[i]
        k = arrK[i]
        ans = fact[n - 1] / (fact[k - 1] * fact[n - k])
        ans=int(ans)
        stdout.write(str(ans))
        stdout.write("\n")


if __name__ == "__main__":
    main()

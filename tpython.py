t = int(input())
fact = [1]*1005
mod = 988244353
for i in range(1,1005):
    fact[i] = (fact[i-1]*i)%mod
while t:
    t-=1
    n = int(input())
    if n % 2 == 1:
        print(0)
        continue
    ans = (fact[n//2]*fact[n//2])%mod
    print(ans)

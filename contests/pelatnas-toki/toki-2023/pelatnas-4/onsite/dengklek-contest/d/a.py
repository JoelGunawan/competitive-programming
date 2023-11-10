a = 0
b = 0
a = int(input())
b = int(input())
sum = 0
for i in range(0, a):
    sum = sum + pow(i + 1, 2019)
print(sum % b)
import numpy as np
import matplotlib.pyplot as plt

# plt.xscale("log")
N = 20
x = []
y = []

for i in range(N):
    l = map(float, raw_input().split())
    x.append(l[0])
    y.append(l[1])
print x
print y
plt.plot(x,y)
plt.xlabel("size")
plt.ylabel("time(s)")
plt.show()


from matplotlib import pyplot as plt
import pandas as pd
import csv

eps = 0.01
step = 0.1

def rosenbrok(x: list):
    return (1 - x[1]) ** 2 + 100 * (x[0] - x[1] ** 2) ** 2

result = [[-1, 2]] 
current_iter = 0
f_1 = 0
f_2 = 1
max_iter = 100

while abs(f_1 - f_2) > eps and current_iter < max_iter:
    for i in range(len(result[-1])):
        value = rosenbrok(result[-1])
        result[-1][i] += step
        new_value = rosenbrok(result[-1])
        
        if new_value >= value:
            result[-1][i] -= 2 * step
            new_value = rosenbrok(result[-1])
            if new_value > value:
                result[-1][i] += step
        result.append(result[-1][:])
    f_1 = f_2
    f_2 = rosenbrok(result[-1])
    current_iter += 1

print("Iter Amount: ", current_iter)

new_result = result[0::]
columns = ['x', 'y', 'z']
with open('fun2_2.csv', 'w') as f:
    write = csv.writer(f)
    write.writerow(columns)
    for coord in new_result:
        coord.append(rosenbrok(coord))
        write.writerow(coord)

df = pd.DataFrame(new_result, columns=columns)
df.to_csv('fun2_1.csv', index=False)

x = df['x']
y = df['y']
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)

plt.scatter(x, y)
plt.plot(x, y, '-o', color='g')
plt.savefig('fun2_2.jpeg')
plt.show()


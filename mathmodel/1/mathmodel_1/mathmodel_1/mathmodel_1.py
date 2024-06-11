import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

def calc():
    a = 2
    b_1 = 0.8
    b_2 = 4
    k = 3
    x = 3
    z_1 = [0]
    z_2 = [0]
    s = 0.01
    h = s
    t = [h]
    y = [0]

    for i in range(1, 101):
        z_1.append(round(z_1[i-1] + h * z_2[i-1], 5))
        z_2.append(round(z_2[i-1] + h * ((x - z_1[i-1] - (b_1 + b_2) * z_2[i-1]) / (b_1 * b_2)), 5))

        y.append(round((k * z_1[i-1]) - ((k * a) * z_2[i-1]), 5))
        h += s
        t.append(round(h, 5))

    data = {'t': t, 'y': y}
    df = pd.DataFrame(data)

    print(df.to_string())
  
    t_values = df['t'].tolist()
    y_values = df['y'].tolist()

    plt.plot(t_values, y_values, color='red', marker='o', markeredgecolor='blue')

    plt.xlabel('t')
    plt.ylabel('y')
    plt.title('y(t)')

    plt.show()

calc()
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import csv
import random
import math



def calc(a, b_1):
    z_1 = [0]
    z_2 = [0]
    s = 0.01
    h = s
    t = [h]
    y = [0]

    for i in range(1, 101):
        z_1.append(round(z_1[i - 1] + h * z_2[i - 1], 3))
        z_2.append(round(z_2[i - 1] + h * ((3.0 - z_1[i - 1] - (b_1 + 4.0) * z_2[i - 1]) / (b_1 * 4.0)), 3))
        y.append(round(3.0 * z_1[i - 1] - (3.0 * a) * z_2[i - 1], 3))
        h += s
        t.append(round(h, 3))
    func_dict = {'t': t, 'y': y}
    return func_dict


def drawGraph(dest_file, dest_csv, func_dict, line_style='-', flag=False):
    dataframe = pd.DataFrame(func_dict)
    dataframe.to_csv(dest_csv, index=False)
    df = pd.read_csv(dest_csv)
    x = df['t']
    y = df['y']
    plt.xlabel('t')
    plt.ylabel('y(t)')
    plt.plot(x, y, line_style)
    plt.savefig(dest_file)
    if flag:
        plt.close()


delta_y = round(0.05 * 8.99997, 3)
iter = 100000

def calcVariables(num_list: list):
    m_calc = round(sum(num_list) / iter, 3)
    d_calc = round(sum([(num - m_calc) ** 2 for num in num_list]) / iter, 3)
    sigma_calc = round(d_calc ** 0.5, 3)
    return m_calc, d_calc, sigma_calc


def mullerGenerator():
    r1, r2 = random.uniform(0, 1), random.uniform(0, 1)
    z = math.cos(2 * math.pi * r1) * (-2 * math.log10(r2)) ** 0.5
    x = z * delta_y
    return x

def create_hist(numbers: list, dest_graph, bins):
    counts, edges, bars = plt.hist(numbers, bins=bins, edgecolor='black', rwidth=0.9, color="green")
    plt.xlabel(' ')
    plt.ylabel(' ')
    plt.savefig(dest_graph)
    return dest_graph

eps = 0.01

def func(coordinates):
    mathFunc = calc(coordinates[0], coordinates[1])
    return sum([(y_a - y_e) ** 2 for y_a, y_e in zip(mathFunc['y'], y_noised)]) / (len(mathFunc['y']) + 1)

def calc_min(func, s, coordinates, max_iter):
    result = [coordinates.copy()]
    current_iter = 0
    f_1 = 0
    f_2 = 1
    while abs(f_1 - f_2) > eps and current_iter < max_iter:
        for i in range(len(coordinates)):
            value = func(coordinates)
            coordinates[i] += s
            new_value = func(coordinates)
            if new_value >= value:
                coordinates[i] -= 2 * s
                new_value = func(coordinates)
                if new_value > value:
                    coordinates[i] += s
            result.append(coordinates.copy())
        f_1 = f_2
        f_2 = func(coordinates)
        current_iter += 1
    result.append(coordinates)
    print("Iter Amount: ", current_iter)
    print(coordinates)
    return result

def exportResults (func, dest_file, dest_graph, selection, result) :
    newResult = result [::selection]
    newResult.append(result[len(result)-1])
    columns = ['a', 'b1', 'cf']
    for coord in newResult :
        coord.append(func(coord))
    with open (dest_file, 'w') as f :
        write = csv.writer(f)
        write.writerow(columns)
        write.writerows(newResult)
    f.close()
    df = pd.read_csv(dest_file, on_bad_lines ='skip')
    x = df['a']
    y = df['b1']
    plt.xlabel('x')
    plt.ylabel('y')
    plt.grid(True)
    plt.plot(x, y , "-o")
    plt.savefig(dest_graph)
    plt.close()

def noise(a, b_1):
    mathFunc = calc(a, b_1)
    iter = len(mathFunc['y'])
    noiseNum = [mullerGenerator() for c in range(iter)]
    y_noised = [round(x, 3) + round(y, 3) for x, y in zip(mathFunc['y'], [noiseNum[c] for c in range(iter)])]
    noisedCoord = {'t': mathFunc['t'], 'y': y_noised}
    drawGraph('laba_4_noize.png', 'laba_4_noize.csv', noisedCoord, flag=False)
    drawGraph('laba_4_function_with_noize.png', 'laba_4_function_with_noize.csv', mathFunc, flag=False)
    return noisedCoord

def cf(y_actual: list, y_noised: list):
    return sum([(y_a - y_e) ** 2 for y_a, y_e in zip(y_actual, y_noised)]) / (len(y_actual) + 1)

def function(coordinates):
    mathFunc = calc(coordinates[0], coordinates[1])
    return cf(y_actual=mathFunc['y'], y_noised=y_noised)

def drawResult(a, b_1, line_style):
    mathFunc = calc(a, b_1)
    drawGraph('lab4_result.png', 'lab4_result.csv', mathFunc, line_style=line_style, flag=False)

if __name__ == '__main__':
    y_noised = noise(a=2.0, b_1=0.8)['y']

        
    find_min = calc_min(func=function, s=0.0000011, coordinates=[2.5, 1.0], max_iter=100000)
    exportResults(function, "exp1.csv", "exp1.png", 1, find_min)
    
    find_min = calc_min(func=function, s=0.000001, coordinates=[2.5, 1.0], max_iter=100000)
    exportResults(function, "exp1_1.csv", "exp1.png", 1, find_min)
    
    find_min = calc_min(func=function, s=0.000001, coordinates=[3.0, 2.0], max_iter=100000)
    exportResults(function, "exp2.csv", "exp2.png", 1, find_min)

    
    find_min = calc_min(func=function, s=0.000001, coordinates=[1.5, 1.0], max_iter=100000)
    exportResults(function, 'exp3.csv', 'exp3.png', 1, find_min)

    find_min = calc_min(func=function, s=0.0000011, coordinates=[1.0, 0.5], max_iter=100000)
    exportResults(function, 'exp4.csv', 'exp4.png', 1, find_min)

    drawResult(2.0, 0.8, line_style='-')
    drawResult(2.5, 1.0, line_style='--')
    drawResult(3.0, 2.0, line_style='--')
    drawResult(1.5, 0.8, line_style='--')
    drawResult(1.0, 0.5, line_style='--')

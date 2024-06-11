from cmath import sqrt
import random
from matplotlib import pyplot as plt
import math


delta_y = round (0.05 * 8.99997 , 4)
print ( delta_y )
iter = 100000

def calcVariables ( numbers_list :list , m_calc , d_calc , sigma_calc ) :
    m_calc = round (sum( numbers_list ) / iter , 4)
    d_calc = round (sum ([( num - m_calc ) **2 for num in numbers_list ]) / iter,4)
    sigma_calc = round ( d_calc ** 0.5 , 4)
    
    return m_calc , d_calc , sigma_calc


def muller_generator () :
    r1 , r2 = random.uniform(0,1), random.uniform(0,1)
    z1 = math.cos(2 * math.pi * r1 ) * ( -2 * math.log10(r2)) ** 0.5
    z2 = math.sin (2 * math.pi * r1 ) * ( -2 * math.log10(r2)) ** 0.5
    x1 = z1 * delta_y
    x2 = z2 * delta_y
    return x1 , x2

def create_hist ( numbers : list , dest_graph , bins ) :
    counts , edges , bars = plt.hist(numbers, bins = bins, edgecolor ="black", rwidth =0.9,color='green')
    plt.bar_label(bars)
    plt.xlabel("Интервалы")
    plt.ylabel("Количество элементов")
    plt.savefig(dest_graph)
    return dest_graph


if __name__ == "__main__":

    random_num = [random.uniform(0 , 1) for n in range (iter)]
    bins = [round( z * 0.1 , 1) for z in range (0, 11)]
    createPlot = create_hist(random_num, "inner.png", bins=bins)
    inner_m = inner_d = inner_sigma = 0
    print (" Вычисления встроенного ГСЧ : M, D, Sigma ", calcVariables ( random_num,inner_m , inner_d , inner_sigma ) )


    muller_numbers = []
    for _ in range (iter) :
        x1 , x2 = muller_generator()
        muller_numbers.append(x1)
        muller_numbers.append(x2)

    muller_bins = [ k * 0.27 for k in range ( -5 , 6) ]
    muller_createPlot = create_hist(muller_numbers , "muller.png", bins = muller_bins )
  
    muller_m = muller_d = muller_sigma = 0
    print (" Вычисления по методу Мюллера : M, D, Sigma ", calcVariables ( muller_numbers , muller_m , muller_d , muller_sigma ) )

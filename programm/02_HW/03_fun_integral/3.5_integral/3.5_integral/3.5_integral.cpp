#include<iostream> 
#include<cmath>

double f(double x) { 
	return x * x; 
}

// Функция для вычисления определенного интеграла методом трапеций 
double CalculateInt(double a, double b, int n, double (*f)(double)) { 
	double h = (b - a) / n; 
	double sum = 0.5 * (f(a) + f(b)); 
	for (int i = 1; i < n; i++) { 
		double x = a + i * h; 
		sum += f(x); 
	} 
	return h * sum; 
}

// Функция для вычисления интеграла с заданной точностью 

double Integral(double a, double b, double eps, double (*f)(double)) { 
	int n = 1000; // начальное количество интервалов 
	double I1 = CalculateInt(a, b, n, f); 
	double I2 = CalculateInt(a, b, 2 * n, f); 
	while (std::abs(I2 - I1) > eps) { 
		n *= 2; I1 = I2; 
		I2 = CalculateInt(a, b, 2 * n, f); 
	} 
	std::cout << "Accuracy: " << std::abs(I2 - I1) << std::endl; //вывод точности по Рунге 
	return I2; 
}

int main() {
	double a = 2.0; //нижний предел 
	double b = 5.0; //верхний предел 
	double eps = 0.0001; // точность


	double result = Integral(a, b, eps, f);

	std::cout << "Result: " << result << std::endl;

	return 0;
}
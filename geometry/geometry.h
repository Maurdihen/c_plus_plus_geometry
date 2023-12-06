#include "iostream"
#include "cmath"
#include "string"

using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);

struct pt {
    double x, y;
    pt(double x1 = 0, double y1 = 0) {
        x = x1;
        y = y1;
    }
    pt operator + (pt b) {
        return pt(x + b.x, y + b.y);
    }
    pt operator - (pt b) {
        return pt(x - b.x, y - b.y);
    }
    pt operator * (double k) {
        return pt(x * k, y * k);
    }
    pt operator / (double k) {
        return pt(x / k, y / k);
    }
};


// Функция для вычисления расстояния от точки до начала координат
double dist(pt a) {
    return a.x * a.x + a.y * a.y;
}

// Функция для вычисления скалярного произведения двух векторов
double ck(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}

// Функция для вычисления векторного произведения двух векторов в 2D
double vc(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

// Функция для вычисления угла между векторами a и b в радианах
double degree(pt a, pt b) {
    return acos(ck(a, b) / (sqrt(dist(a)) * sqrt(dist(b))));
}

// Функция для вычисления площади треугольника, образованного тремя точками
double s_tr(pt a, pt b, pt c) {
    return fabs(vc(a - b, c - b) / 2.0);
}

// Функция для вычисления полярного угла между векторами a и b
double polar_degree(pt a, pt b) {
    return atan2(vc(a, b), ck(a, b));
}

// Функция для получения вектора, перпендикулярного заданному
pt perp(pt a) {
    return pt(a.y, -a.x);
}

// Функция для получения вектора заданной длины и направления
pt norm(pt a, int k) {
    return (a / sqrt(dist(a))) * k;
}

// Функция для нахождения биссектрисы угла между векторами ab и ac
pt bisector(pt a, pt b, pt c) {
    return norm(norm(b - a, 1) + norm(c - a, 1), 1);
}

// Функция для нахождения расстояния от точки p до прямой, заданной точками a и b
double point_line_distance(pt a, pt b, pt p) {
    return fabs(vc(b - a, p - a)) / sqrt(dist(b - a));
}

// Функция для проверки, лежит ли точка p на прямой, заданной точками a и b
bool point_on_line(pt a, pt b, pt p) {
    return fabs(fabs(vc(b - a, p - a))) < eps && fabs(sqrt(dist(b - a))) > eps;
}

// Функция для определения с какой стороны прямой, заданной точками a и b, находится точка p
string point_side_line(pt a, pt b, pt p) {
    double temp = vc(b - a, p - a);

    if (fabs(temp) < eps) {
        return "ON_LINE";
    } else if (temp > 0) {
        return "LEFT";
    } else {
        return "RIGHT";
    }
}

// Функция для проверки параллельности прямых, заданных точками a, b и c, d
bool line_parallel(pt a, pt b, pt c, pt d) {
    return fabs(fabs(vc(b - a, d - c))) < eps;
}

// Функция для проверки, лежит ли точка q на отрезке, заданном точками a и b
bool point_otr(pt a, pt b, pt q) {
    if (fabs(vc(b - a, q - a)) > eps) {
        return false;
    }

    return ck(q - a, b - a) >= -eps && ck(q - a, b - a) <= dist(b - a) + eps;
}

// Функция для вычисления расстояния от точки p до отрезка, заданного точками a и b
double point_otr_distance(pt a, pt b, pt p) {
    double temp = ck(p - a, b - a) / dist(b - a);

    if (temp < 0) {
        return sqrt(dist(p - a));
    } else if (temp > 1) {
        return sqrt(dist(p - b));
    } else {
        return sqrt(dist(p - a + b - a * (temp / dist(b - a))));
    }
}




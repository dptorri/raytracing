#ifndef RAYTRACING_GEOMETRY_H
#define RAYTRACING_GEOMETRY_H

#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

// Defining magic numbers as constants
constexpr size_t DIM2 = 2;
constexpr size_t DIM3 = 3;
constexpr size_t DIM4 = 4;

// Generic Vector Struct
template <size_t DIM, typename T>
struct vec {
    // STL style typedefs
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;

    vec() {
        for (size_t i = DIM; i--; data_[i] = T());
    }
    // Access Vector Element via []
    T& operator[](const size_t i) {
        assert(i < DIM);
        return data_[i];
    }
    // Access Vector Element via [] (constant)
    const T& operator[](const size_t i) const {
        assert(i < DIM);
        return data_[i];
    }

private:
    T data_[DIM];
};

typedef vec<DIM2, float> Vec2f;
typedef vec<DIM3, float> Vec3f;
typedef vec<DIM3, int  > Vec3i;
typedef vec<DIM4, float> Vec4f;

// 2D Vector Specialization
template <typename T>
struct vec<DIM2, T> {
    vec() : x(T()), y(T()) {}
    vec(T X, T Y) : x(X), y(Y) {}

    // Access 2D Vector Element via []
    T& operator[](const size_t i) {
        assert(i < DIM2);
        return i == 0 ? x : y;
    }
    // Access 2D Vector Element via [] (constant)
    const T& operator[](const size_t i) const {
        assert(i < DIM2);
        return i == 0 ? x : y;
    }
    T x,y;
};

// 3D Vector Specialization
template <typename T>
struct vec<DIM3, T> {
    vec() : x(T()), y(T()), z(T()) {}
    vec(T X, T Y, T Z) : x(X), y(Y), z(Z) {}

    // Access 3D Vector Element via []
    T& operator[](const size_t i) {
        assert(i < DIM3);
        return i == 0 ? x : (i == 1 ? y : z);
    }
    // Access 3D Vector Element via [] (constant)
    const T& operator[](const size_t i) const {
        assert(i < DIM3);
        return i == 0 ? x : (i == 1 ? y : z);
    }

    T x,y,z;
};

// 4D Vector Specialization
template <typename T>
struct vec<DIM4, T> {
    vec() : x(T()), y(T()), z(T()), w(T()) {}
    vec(T X, T Y, T Z, T W) : x(X), y(Y), z(Z), w(W) {}

    // Access 4D Vector Element via []
    T& operator[](const size_t i) {
        assert(i < DIM4);
        return i == 0 ? x : (i == 1 ? y : (i == 2 ? z : w));
    }
    // Access 4D Vector Element via [] (constant)
    const T& operator[](const size_t i) const {
        assert(i < DIM4);
        return i == 0 ? x : (i == 1 ? y : (i == 2 ? z : w));
    }

    T x,y,z,w;
};

#endif //RAYTRACING_GEOMETRY_H

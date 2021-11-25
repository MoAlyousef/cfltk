#include <stddef.h>
#include <string.h>

#ifndef __CFL_VEC_H__
#define __CFL_VEC_H__

template <typename T>
class Vec {
    size_t cap = 4;
    size_t len = 0;
    T *arr;

    inline void reallocate();

  public:
    Vec() noexcept;
    explicit Vec(size_t n);
    Vec(size_t n, const T &val);
    template <class InputIt>
    Vec(InputIt first, InputIt last);
    Vec(const Vec<T> &);
    ~Vec();
    Vec<T> &operator=(const Vec<T> &);
    void assign(size_t, const T &value);
    template <class InputIt>
    void assign(InputIt, InputIt);

    T* begin() noexcept;
    const T *cbegin() const noexcept;
    T* end() noexcept;
    const T *cend() const noexcept;

    bool empty() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;
    void resize(size_t);
    void resize(size_t, const T &);
    void reserve(size_t);
    void shrink_to_fit();

    T &operator[](size_t);
    const T &operator[](size_t) const;
    T &at(size_t);
    const T &at(size_t) const;
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    T *data() noexcept;
    const T *data() const noexcept;

    void push_back(const T &);
    void pop_back();

    T* insert(const T *, const T &);
    T* insert(const T *, size_t, const T &);
    template <class InputIt>
    T* insert(const T *, InputIt, InputIt);
    T* erase(const T *);
    T* erase(const T *, const T *);
    void swap(Vec<T> &);
    void clear() noexcept;

    bool operator==(const Vec<T> &) const;
    bool operator!=(const Vec<T> &) const;
    bool operator<(const Vec<T> &) const;
    bool operator<=(const Vec<T> &) const;
    bool operator>(const Vec<T> &) const;
    bool operator>=(const Vec<T> &) const;
};

template <typename T>
Vec<T>::Vec() noexcept {
    arr = new T[cap];
}

template <typename T>
Vec<T>::Vec(size_t n) {
    size_t i;
    cap = n;
    arr = new T[cap];
    for (i = 0; i < n; ++i)
        arr[i] = T();
    len = n;
}

template <typename T>
Vec<T>::Vec(size_t n, const T &value) {
    size_t i;
    cap = n;
    arr = new T[cap];
    for (i = 0; i < n; ++i)
        arr[i] = value;
    len = n;
}

template <typename T>
template <class InputIt>
Vec<T>::Vec(InputIt first, InputIt last) {
    size_t i, count = last - first;
    cap = count;
    len = count;
    arr = new T[cap];
    for (i = 0; i < count; ++i, ++first)
        arr[i] = *first;
}

template <typename T>
Vec<T>::Vec(const Vec<T> &other) {
    size_t i;
    cap = other.cap;
    arr = new T[cap];
    for (i = 0; i < other.len; ++i)
        arr[i] = other.arr[i];
    len = other.len;
}

template <typename T>
Vec<T>::~Vec() {
    delete[] arr;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &other) {

    if (this == &other) {
        return *this;
    }
    size_t i;
    if (cap < other.len) {
        cap = other.len;
        reallocate();
    }
    for (i = 0; i < other.len; ++i)
        arr[i] = other.arr[i];
    len = other.len;
}

template <typename T>
void Vec<T>::assign(size_t count, const T &value) {
    size_t i;
    if (count > cap) {
        cap = count;
        reallocate();
    }
    for (i = 0; i < count; ++i)
        arr[i] = value;
    len = count;
}

template <typename T>
template <class InputIt>
void Vec<T>::assign(InputIt first, InputIt last) {
    size_t i, count = last - first;
    if (count > cap) {
        cap = count;
        reallocate();
    }
    for (i = 0; i < count; ++i, ++first)
        arr[i] = *first;
    len = count;
}

template <typename T>
T* Vec<T>::begin() noexcept {
    return arr;
}

template <typename T>
const T *Vec<T>::cbegin() const noexcept {
    return arr;
}

template <typename T>
T* Vec<T>::end() noexcept {
    return arr + len;
}

template <typename T>
const T *Vec<T>::cend() const noexcept {
    return arr + len;
}

template <typename T>
inline void Vec<T>::reallocate() {
    T *tarr = new T[cap];
    memcpy(tarr, arr, len * sizeof(T));
    delete[] arr;
    arr = tarr;
}

template <typename T>
bool Vec<T>::empty() const noexcept {
    return len == 0;
}

template <typename T>
size_t Vec<T>::size() const noexcept {
    return len;
}

template <typename T>
size_t Vec<T>::capacity() const noexcept {
    return cap;
}

template <typename T>
void Vec<T>::resize(size_t sz) {
    if (sz > len) {
        if (sz > cap) {
            cap = sz;
            reallocate();
        }
    } else {
        size_t i;
        for (i = len; i < sz; ++i)
            arr[i].~T();
    }
    len = sz;
}

template <typename T>
void Vec<T>::resize(size_t sz, const T &c) {
    if (sz > len) {
        if (sz > cap) {
            cap = sz;
            reallocate();
        }
        size_t i;
        for (i = len; i < sz; ++i)
            arr[i] = c;
    } else {
        size_t i;
        for (i = len; i < sz; ++i)
            arr[i].~T();
    }
    len = sz;
}

template <typename T>
void Vec<T>::reserve(size_t _sz) {
    if (_sz > cap) {
        cap = _sz;
        reallocate();
    }
}

template <typename T>
void Vec<T>::shrink_to_fit() {
    cap = len;
    reallocate();
}

template <typename T>
T &Vec<T>::operator[](size_t idx) {
    return arr[idx];
}

template <typename T>
const T &Vec<T>::operator[](size_t idx) const {
    return arr[idx];
}

template <typename T>
T &Vec<T>::at(size_t pos) {
    return arr[pos];
}

template <typename T>
const T &Vec<T>::at(size_t pos) const {
    return arr[pos];
}

template <typename T>
T &Vec<T>::front() {
    return arr[0];
}

template <typename T>
const T &Vec<T>::front() const {
    return arr[0];
}

template <typename T>
T &Vec<T>::back() {
    return arr[len - 1];
}

template <typename T>
const T &Vec<T>::back() const {
    return arr[len - 1];
}

template <typename T>
T *Vec<T>::data() noexcept {
    return arr;
}

template <typename T>
const T *Vec<T>::data() const noexcept {
    return arr;
}

template <typename T>
void Vec<T>::push_back(const T &val) {
    if (len == cap) {
        cap *= 2;
        reallocate();
    }
    arr[len] = val;
    ++len;
}

template <typename T>
void Vec<T>::pop_back() {
    --len;
    arr[len].~T();
}

template <typename T>
T* Vec<T>::insert(const T *it, const T &val) {
    T* iit = &arr[it - arr];
    if (len == cap) {
        cap *= 2;
        reallocate();
    }
    memmove(iit + 1, iit, (len - (it - arr)) * sizeof(T));
    (*iit) = val;
    ++len;
    return iit;
}

template <typename T>
T* Vec<T>::insert(const T *it, size_t cnt, const T &val) {
    T* f = &arr[it - arr];
    if (!cnt)
        return f;
    if (len + cnt > cap) {
        cap = (len + cnt);
        reallocate();
    }
    memmove(f + cnt, f, (len - (it - arr)) * sizeof(T));
    len += cnt;
    for (T* it = f; cnt--; ++it)
        (*it) = val;
    return f;
}

template <typename T>
template <class InputIt>
T* Vec<T>::insert(const T *it, InputIt first, InputIt last) {
    T* f = &arr[it - arr];
    size_t cnt = last - first;
    if (!cnt)
        return f;
    if (len + cnt > cap) {
        cap = (len + cnt);
        reallocate();
    }
    memmove(f + cnt, f, (len - (it - arr)) * sizeof(T));
    for (T* it = f; first != last; ++it, ++first)
        (*it) = *first;
    len += cnt;
    return f;
}

template <typename T>
T* Vec<T>::erase(const T *it) {
    T* iit = &arr[it - arr];
    (*iit).~T();
    memmove(iit, iit + 1, (len - (it - arr) - 1) * sizeof(T));
    --len;
    return iit;
}

template <typename T>
T* Vec<T>::erase(const T *first, const T *last) {
    T* f = &arr[first - arr];
    if (first == last)
        return f;
    for (; first != last; ++first)
        (*first).~T();
    memmove(f, last, (len - (last - arr)) * sizeof(T));
    len -= last - first;
    return f;
}

template <typename T>
void Vec<T>::swap(Vec<T> &rhs) {
    size_t tlen = len, tcap = cap;
    T *tarr = arr;

    len = rhs.len;
    cap = rhs.cap;
    arr = rhs.arr;

    rhs.len = tlen;
    rhs.cap = tcap;
    rhs.arr = tarr;
}

template <typename T>
void Vec<T>::clear() noexcept {
    size_t i;
    for (i = 0; i < len; ++i)
        arr[i].~T();
    len = 0;
}

template <typename T>
bool Vec<T>::operator==(const Vec<T> &rhs) const {
    if (len != rhs.len)
        return false;
    size_t i;
    for (i = 0; i < len; ++i)
        if (arr[i] != rhs.arr[i])
            return false;
    return true;
}

template <typename T>
bool Vec<T>::operator!=(const Vec<T> &rhs) const {
    if (len != rhs.len)
        return true;
    size_t i;
    for (i = 0; i < len; ++i)
        if (arr[i] != rhs.arr[i])
            return true;
    return false;
}

template <typename T>
bool Vec<T>::operator<(const Vec<T> &rhs) const {
    size_t i, j, ub = len < rhs.len ? len : rhs.len;
    for (i = 0; i < ub; ++i)
        if (arr[i] != rhs.arr[i])
            return arr[i] < rhs.arr[i];
    return len < rhs.len;
}

template <typename T>
bool Vec<T>::operator<=(const Vec<T> &rhs) const {
    size_t i, j, ub = len < rhs.len ? len : rhs.len;
    for (i = 0; i < ub; ++i)
        if (arr[i] != rhs.arr[i])
            return arr[i] < rhs.arr[i];
    return len <= rhs.len;
}

template <typename T>
bool Vec<T>::operator>(const Vec<T> &rhs) const {
    size_t i, j, ub = len < rhs.len ? len : rhs.len;
    for (i = 0; i < ub; ++i)
        if (arr[i] != rhs.arr[i])
            return arr[i] > rhs.arr[i];
    return len > rhs.len;
}

template <typename T>
bool Vec<T>::operator>=(const Vec<T> &rhs) const {
    size_t i, j, ub = len < rhs.len ? len : rhs.len;
    for (i = 0; i < ub; ++i)
        if (arr[i] != rhs.arr[i])
            return arr[i] > rhs.arr[i];
    return len >= rhs.len;
}

#endif
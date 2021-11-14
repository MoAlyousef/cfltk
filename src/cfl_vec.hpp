#include <stddef.h>
#include <string.h>

#ifndef CFL_VEC_H
#define CFL_VEC_H

template <typename T>
class Vec {
  public:
    typedef T value_type;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef ptrdiff_t difference_type;
    typedef unsigned int size_type;

    // 23.3.11.2, construct/copy/destroy:
    Vec() noexcept;
    explicit Vec(size_type n);
    Vec(size_type n, const T &val);
    template <class InputIt>
    Vec(InputIt first, InputIt last); // v1(v2.begin(),v2.end())
    Vec(const Vec<T> &);
    ~Vec();
    Vec<T> &operator=(const Vec<T> &);
    void assign(size_type, const T &value);
    template <class InputIt>
    void assign(InputIt, InputIt);

    iterator begin() noexcept;
    const_iterator cbegin() const noexcept;
    iterator end() noexcept;
    const_iterator cend() const noexcept;

    bool empty() const noexcept;
    size_type size() const noexcept;
    size_type capacity() const noexcept;
    void resize(size_type);
    void resize(size_type, const T &);
    void reserve(size_type);
    void shrink_to_fit();

    reference operator[](size_type);
    const_reference operator[](size_type) const;
    reference at(size_type);
    const_reference at(size_type) const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    T *data() noexcept;
    const T *data() const noexcept;

    void push_back(const T &);
    void pop_back();

    iterator insert(const_iterator, const T &);
    iterator insert(const_iterator, size_type, const T &);
    template <class InputIt>
    iterator insert(const_iterator, InputIt, InputIt);
    iterator erase(const_iterator);
    iterator erase(const_iterator, const_iterator);
    void swap(Vec<T> &);
    void clear() noexcept;

    bool operator==(const Vec<T> &) const;
    bool operator!=(const Vec<T> &) const;
    bool operator<(const Vec<T> &) const;
    bool operator<=(const Vec<T> &) const;
    bool operator>(const Vec<T> &) const;
    bool operator>=(const Vec<T> &) const;

  private:
    size_type rsrv_sz = 4;
    size_type vec_sz = 0;
    T *arr;

    inline void reallocate();
};

template <typename T>
Vec<T>::Vec() noexcept {
    arr = new T[rsrv_sz];
}

template <typename T>
Vec<T>::Vec(typename Vec<T>::size_type n) {
    size_type i;
    rsrv_sz = n << 2;
    arr = new T[rsrv_sz];
    for (i = 0; i < n; ++i)
        arr[i] = T();
    vec_sz = n;
}

template <typename T>
Vec<T>::Vec(typename Vec<T>::size_type n, const T &value) {
    size_type i;
    rsrv_sz = n << 2;
    arr = new T[rsrv_sz];
    for (i = 0; i < n; ++i)
        arr[i] = value;
    vec_sz = n;
}

template <typename T>
template <class InputIt>
Vec<T>::Vec(InputIt first, InputIt last) {
    size_type i, count = last - first;
    rsrv_sz = count << 2;
    vec_sz = count;
    arr = new T[rsrv_sz];
    for (i = 0; i < count; ++i, ++first)
        arr[i] = *first;
}

template <typename T>
Vec<T>::Vec(const Vec<T> &other) {
    size_type i;
    rsrv_sz = other.rsrv_sz;
    arr = new T[rsrv_sz];
    for (i = 0; i < other.vec_sz; ++i)
        arr[i] = other.arr[i];
    vec_sz = other.vec_sz;
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
    size_type i;
    if (rsrv_sz < other.vec_sz) {
        rsrv_sz = other.vec_sz << 2;
        reallocate();
    }
    for (i = 0; i < other.vec_sz; ++i)
        arr[i] = other.arr[i];
    vec_sz = other.vec_sz;
}

template <typename T>
void Vec<T>::assign(typename Vec<T>::size_type count, const T &value) {
    size_type i;
    if (count > rsrv_sz) {
        rsrv_sz = count << 2;
        reallocate();
    }
    for (i = 0; i < count; ++i)
        arr[i] = value;
    vec_sz = count;
}

template <typename T>
template <class InputIt>
void Vec<T>::assign(InputIt first, InputIt last) {
    size_type i, count = last - first;
    if (count > rsrv_sz) {
        rsrv_sz = count << 2;
        reallocate();
    }
    for (i = 0; i < count; ++i, ++first)
        arr[i] = *first;
    vec_sz = count;
}

template <typename T>
typename Vec<T>::iterator Vec<T>::begin() noexcept {
    return arr;
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::cbegin() const noexcept {
    return arr;
}

template <typename T>
typename Vec<T>::iterator Vec<T>::end() noexcept {
    return arr + vec_sz;
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::cend() const noexcept {
    return arr + vec_sz;
}

template <typename T>
inline void Vec<T>::reallocate() {
    T *tarr = new T[rsrv_sz];
    memcpy(tarr, arr, vec_sz * sizeof(T));
    delete[] arr;
    arr = tarr;
}

template <typename T>
bool Vec<T>::empty() const noexcept {
    return vec_sz == 0;
}

template <typename T>
typename Vec<T>::size_type Vec<T>::size() const noexcept {
    return vec_sz;
}

template <typename T>
typename Vec<T>::size_type Vec<T>::capacity() const noexcept {
    return rsrv_sz;
}

template <typename T>
void Vec<T>::resize(typename Vec<T>::size_type sz) {
    if (sz > vec_sz) {
        if (sz > rsrv_sz) {
            rsrv_sz = sz;
            reallocate();
        }
    } else {
        size_type i;
        for (i = vec_sz; i < sz; ++i)
            arr[i].~T();
    }
    vec_sz = sz;
}

template <typename T>
void Vec<T>::resize(typename Vec<T>::size_type sz, const T &c) {
    if (sz > vec_sz) {
        if (sz > rsrv_sz) {
            rsrv_sz = sz;
            reallocate();
        }
        size_type i;
        for (i = vec_sz; i < sz; ++i)
            arr[i] = c;
    } else {
        size_type i;
        for (i = vec_sz; i < sz; ++i)
            arr[i].~T();
    }
    vec_sz = sz;
}

template <typename T>
void Vec<T>::reserve(typename Vec<T>::size_type _sz) {
    if (_sz > rsrv_sz) {
        rsrv_sz = _sz;
        reallocate();
    }
}

template <typename T>
void Vec<T>::shrink_to_fit() {
    rsrv_sz = vec_sz;
    reallocate();
}

template <typename T>
typename Vec<T>::reference Vec<T>::operator[](typename Vec<T>::size_type idx) {
    return arr[idx];
}

template <typename T>
typename Vec<T>::const_reference Vec<T>::operator[](typename Vec<T>::size_type idx) const {
    return arr[idx];
}

template <typename T>
typename Vec<T>::reference Vec<T>::at(size_type pos) {
    return arr[pos];
}

template <typename T>
typename Vec<T>::const_reference Vec<T>::at(size_type pos) const {
    return arr[pos];
}

template <typename T>
typename Vec<T>::reference Vec<T>::front() {
    return arr[0];
}

template <typename T>
typename Vec<T>::const_reference Vec<T>::front() const {
    return arr[0];
}

template <typename T>
typename Vec<T>::reference Vec<T>::back() {
    return arr[vec_sz - 1];
}

template <typename T>
typename Vec<T>::const_reference Vec<T>::back() const {
    return arr[vec_sz - 1];
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
    if (vec_sz == rsrv_sz) {
        rsrv_sz <<= 2;
        reallocate();
    }
    arr[vec_sz] = val;
    ++vec_sz;
}

template <typename T>
void Vec<T>::pop_back() {
    --vec_sz;
    arr[vec_sz].~T();
}

template <typename T>
typename Vec<T>::iterator Vec<T>::insert(typename Vec<T>::const_iterator it, const T &val) {
    iterator iit = &arr[it - arr];
    if (vec_sz == rsrv_sz) {
        rsrv_sz <<= 2;
        reallocate();
    }
    memmove(iit + 1, iit, (vec_sz - (it - arr)) * sizeof(T));
    (*iit) = val;
    ++vec_sz;
    return iit;
}

template <typename T>
typename Vec<T>::iterator Vec<T>::insert(typename Vec<T>::const_iterator it,
                                         typename Vec<T>::size_type cnt, const T &val) {
    iterator f = &arr[it - arr];
    if (!cnt)
        return f;
    if (vec_sz + cnt > rsrv_sz) {
        rsrv_sz = (vec_sz + cnt) << 2;
        reallocate();
    }
    memmove(f + cnt, f, (vec_sz - (it - arr)) * sizeof(T));
    vec_sz += cnt;
    for (iterator it = f; cnt--; ++it)
        (*it) = val;
    return f;
}

template <typename T>
template <class InputIt>
typename Vec<T>::iterator Vec<T>::insert(typename Vec<T>::const_iterator it, InputIt first,
                                         InputIt last) {
    iterator f = &arr[it - arr];
    size_type cnt = last - first;
    if (!cnt)
        return f;
    if (vec_sz + cnt > rsrv_sz) {
        rsrv_sz = (vec_sz + cnt) << 2;
        reallocate();
    }
    memmove(f + cnt, f, (vec_sz - (it - arr)) * sizeof(T));
    for (iterator it = f; first != last; ++it, ++first)
        (*it) = *first;
    vec_sz += cnt;
    return f;
}

template <typename T>
typename Vec<T>::iterator Vec<T>::erase(typename Vec<T>::const_iterator it) {
    iterator iit = &arr[it - arr];
    (*iit).~T();
    memmove(iit, iit + 1, (vec_sz - (it - arr) - 1) * sizeof(T));
    --vec_sz;
    return iit;
}

template <typename T>
typename Vec<T>::iterator Vec<T>::erase(typename Vec<T>::const_iterator first,
                                        typename Vec<T>::const_iterator last) {
    iterator f = &arr[first - arr];
    if (first == last)
        return f;
    for (; first != last; ++first)
        (*first).~T();
    memmove(f, last, (vec_sz - (last - arr)) * sizeof(T));
    vec_sz -= last - first;
    return f;
}

template <typename T>
void Vec<T>::swap(Vec<T> &rhs) {
    size_t tvec_sz = vec_sz, trsrv_sz = rsrv_sz;
    T *tarr = arr;

    vec_sz = rhs.vec_sz;
    rsrv_sz = rhs.rsrv_sz;
    arr = rhs.arr;

    rhs.vec_sz = tvec_sz;
    rhs.rsrv_sz = trsrv_sz;
    rhs.arr = tarr;
}

template <typename T>
void Vec<T>::clear() noexcept {
    size_type i;
    for (i = 0; i < vec_sz; ++i)
        arr[i].~T();
    vec_sz = 0;
}

template <typename T>
bool Vec<T>::operator==(const Vec<T> &rhs) const {
    if (vec_sz != rhs.vec_sz)
        return false;
    size_type i;
    for (i = 0; i < vec_sz; ++i)
        if (arr[i] != rhs.arr[i])
            return false;
    return true;
}

template <typename T>
bool Vec<T>::operator!=(const Vec<T> &rhs) const {
    if (vec_sz != rhs.vec_sz)
        return true;
    size_type i;
    for (i = 0; i < vec_sz; ++i)
        if (arr[i] != rhs.arr[i])
            return true;
    return false;
}

template <typename T>
bool Vec<T>::operator<(const Vec<T> &rhs) const {
    size_type i, j, ub = vec_sz < rhs.vec_sz ? vec_sz : rhs.vec_sz;
    for (i = 0; i < ub; ++i)
        if (arr[i] != rhs.arr[i])
            return arr[i] < rhs.arr[i];
    return vec_sz < rhs.vec_sz;
}

template <typename T>
bool Vec<T>::operator<=(const Vec<T> &rhs) const {
    size_type i, j, ub = vec_sz < rhs.vec_sz ? vec_sz : rhs.vec_sz;
    for (i = 0; i < ub; ++i)
        if (arr[i] != rhs.arr[i])
            return arr[i] < rhs.arr[i];
    return vec_sz <= rhs.vec_sz;
}

template <typename T>
bool Vec<T>::operator>(const Vec<T> &rhs) const {
    size_type i, j, ub = vec_sz < rhs.vec_sz ? vec_sz : rhs.vec_sz;
    for (i = 0; i < ub; ++i)
        if (arr[i] != rhs.arr[i])
            return arr[i] > rhs.arr[i];
    return vec_sz > rhs.vec_sz;
}

template <typename T>
bool Vec<T>::operator>=(const Vec<T> &rhs) const {
    size_type i, j, ub = vec_sz < rhs.vec_sz ? vec_sz : rhs.vec_sz;
    for (i = 0; i < ub; ++i)
        if (arr[i] != rhs.arr[i])
            return arr[i] > rhs.arr[i];
    return vec_sz >= rhs.vec_sz;
}

#endif
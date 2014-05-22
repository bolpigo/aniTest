#ifndef STL_CONSTRUCT_H
#define STL_CONSTRUCT_H
#include <new.h> //for placement new
template <class T1, class T2>
inline void construct(T1 *p, const T2 &value) {
	new(p) T1(value);//placement new call T1::T1(value);
}

//destory() 1st, reseive one parameter
template <class T>
inline void destroy(T *pointer) {
	pointer->~T();//call dtor ~T();
}

//destory() 2st, reseive two iterators.
template <class ForwardIterator>
inline void destroy(ForwardIterator first, ForwardIterator last) {
	__destroy(first, last, value_type(first));
}

//judge the value_type has trivial destructor or not
template <class ForwardIterator, class T>
inline __destroy(ForwardIterator first, ForwardIterator last, T *) {
	typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
	__destroy_aux(first, last, trivial_destructor());
}

//if value_type has non-trivial destructor
template <class ForwardIterator>
inline void __destroy_aux(ForwardIterator first, ForwardIterator last, __false_type) {
	for(; first < last; ++first)
		destroy(&*first);
}

//if value_type has trivial destructor...
template <class ForwardIterator>
inline void __destroy_aux(ForwardIterator,ForwardIterator,__true_type){}

//destroy() 3rd, spacilize to iterator with char* and wchar_t*
inline void destroy(char *, char *) {}
inline void destroy(wchar_t *, wchar_t *) {}
#endif

#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP
#include <memory>
#include "iostream"
#include <stdexcept>

namespace ft
{
	template<typename vector>
	class vectorIterator{
	public:
		typedef typename vector::value_type valuetype;
		typedef  valuetype* 		ptrType;
		typedef  valuetype& 		refType;
		
		vectorIterator(ptrType ptr) : i_ptr(ptr){};
		~vectorIterator(){};
		vectorIterator(vectorIterator & rhs) : i_ptr(rhs.i_ptr){};
		vectorIterator & operator=(vectorIterator & rhs){ this->i_ptr = rhs.i_ptr; return *this;};
	private:
		ptrType i_ptr;
	public:
		vectorIterator & operator++(){
			i_ptr++;
			return *this;}
		
		vectorIterator & operator++(int){
			vectorIterator temp = *this;
			++i_ptr;
			return temp;}
		
		
		vectorIterator & operator--(){
			i_ptr--;
			return *this;}
			
		vectorIterator & operator--(int){
			vectorIterator temp = *this;
			--i_ptr;
			return temp;}
		
		vectorIterator & operator+(vectorIterator & add){
			i_ptr += add;
			return *this;}
		
		vectorIterator & operator+(int add){
			i_ptr += add;
			return *this;}
		
		vectorIterator & operator-(vectorIterator & sub){
			i_ptr -= sub;
			return *this;}
		
		vectorIterator & operator-(int sub){
			i_ptr -= sub;
			return *this;}
			
		bool	operator>(vectorIterator & rhs){
			return (this->i_ptr > rhs.i_ptr);
		}
		
		bool	operator>=(vectorIterator & rhs){
			return (this->i_ptr >= rhs.i_ptr);
		}
		
		bool	operator<(vectorIterator & rhs){
			return (this->i_ptr < rhs.i_ptr);
		}
		
		bool	operator<=(vectorIterator & rhs){
			return (this->i_ptr <= rhs.i_ptr);
		}
		
		bool	operator==(vectorIterator & rhs){
			return (this->i_ptr == rhs.i_ptr);
		}
		
		bool	operator!=(vectorIterator & rhs){
			return (this->i_ptr != rhs.i_ptr);
		}
	};
	

	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T                                        	value_type;
		typedef Allocator									allocator_type;
		typedef size_t  									size_type;
		std::ptrdiff_t 										difference_type;
		typedef typename allocator_type::reference      	reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer         	pointer;
		typedef typename allocator_type::const_pointer   	const_pointer;
		typedef vectorIterator<T>                   		iterator;
//		typedef implementation-defined                   const_iterator;
//		typedef std::reverse_iterator<iterator>          reverse_iterator;
//		typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
		/*Default constructor*/
		/*Fill constructor*/
//		explicit vector(size_t n, const value_type& val = value_type()) : size_type(n){ };
		
	private:
		value_type	*_vector;
		allocator_type _alloc;
		size_type 		_size;
		size_type 		_capacity;
		/*(1)*/
	public:
		/*Default constructor*/
		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0){
			_vector = _alloc.allocate(0);
		};
		/*Fill constructor*/
		explicit vector(size_t n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n),  _capacity(n + 1){
			_vector = _alloc.allocate(_capacity);
			for(size_t i = 0; i < _size; i++)
				_vector[i] = val;
		};
		
		
//		/*(2)*/explicit vector (size_type n, const value_type& val = value_type(),                 const allocator_type& alloc = allocator_type());
//		/*(3)*/
//	(3) range constructor
//	Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.template <class InputIterator>         vector (InputIterator first, InputIterator last,                 const allocator_type& alloc = allocator_type());
//		/*(4)*/vector (const vector& x);
//	(4) copy constructor
//	Constructs a container with a copy of each of the elements in x, in the same order*/
	
		/*Capacity functions*/
		//return nb of element in vector
		size_type size() const {return _size;};
		
		//return max capacity
		size_type max_size() const{return _capacity;};
		
//		void resize (size_type n, value_type val = value_type()){
//			if (n < size())
//
//		};
/*Change size
Resizes the container so that it contains n elements.

If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).

If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.

Notice that this function changes the actual content of the container by inserting or erasing elements from it.*/
		

		
		/*size_type capacity() const;
Return size of allocated storage capacity
Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.

This capacity is not necessarily equal to the vector size. It can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.

Notice that this capacity does not suppose a limit on the size of the vector. When this capacity is exhausted and more is needed, it is automatically expanded by the container (reallocating it storage space). The theoretical limit on the size of a vector is given by member max_size.

The capacity of a vector can be explicitly altered by calling member vector::reserve.*/
		
		
		/*bool empty() const;
Test whether vector is empty
Returns whether the vector is empty (i.e. whether its size is 0).

This function does not modify the container in any way. To clear the content of a vector, see vector::clear.*/
		
		/*void reserve (size_type n);
Request a change in capacity
Requests that the vector capacity be at least enough to contain n elements.

If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).

In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.

This function has no effect on the vector size and cannot alter its elements.*/
		
		/*std::vector::shrink_to_fit
void shrink_to_fit();
Shrink to fit
Requests the container to reduce its capacity to fit its size.

The request is non-binding, and the container implementation is free to optimize otherwise and leave the vector with a capacity greater than its size.

This may cause a reallocation, but has no effect on the vector size and cannot alter its elements.*/
		
		reference operator[](size_type n){
			if (n < size())
				return _vector[n];
			else
				return _vector[_size];
		};
		
		const_reference operator[] (size_type n) const{
			if (n < size())
				return _vector[n];
			else
				return _vector[_size];
		};
		
		reference at (size_type n){
				if (n < size())
					return _vector[n];
				else
					throw std::out_of_range("vector");
		};
		
		const_reference at (size_type n) const{
			if (n < size())
				return _vector[n];
			else
				throw std::out_of_range("vector");
		};
		
		reference front(){
				return _vector[0];
		};
		
		const_reference front() const{
			return _vector[0];
		};
		
		reference back(){
				return _vector[_size];
		};
		
		const_reference back() const{
			return _vector[_size];
			
		};
		
		value_type* data(){
			return _vector;
		};
		
		
		
		
		//iterator functions
	/* 																																																							*/
		iterator begin(){
			return _vector;
		}
		iterator end(){
			return _vector + _size;
		}
			//fonction de test
		void	printVector(){
			for(size_t  i = 0; i < _size; i++)
				std::cout << _vector[i];
		};

	};

	
}
#endif





/*
value_type	The first template parameter (T)

allocator_type	The second template parameter (Alloc)	defaults to: allocator<value_type>

reference	allocator_type::reference	for the default allocator: value_type&

const_reference	allocator_type::const_reference	for the default allocator: const value_type&

pointer	allocator_type::pointer	for the default allocator: value_type*

const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*

iterator	a random access iterator to value_type	convertible to const_iterator

const_iterator	a random access iterator to const value_type

reverse_iterator	reverse_iterator<iterator>

const_reverse_iterator	reverse_iterator<const_iterator>

difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t

size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
 
 
 Member functions
(constructor)	Construct vector (public member function)
(destructor)	Vector destructor (public member function)
operator=	Assign content (public member function)

Iterators:
begin	Return iterator to beginning (public member function)
end	Return iterator to end (public member function)
rbegin	Return reverse iterator to reverse beginning (public member function)
rend	Return reverse iterator to reverse end (public member function)
cbegin	Return const_iterator to beginning (public member function)
cend	Return const_iterator to end (public member function)
crbegin	Return const_reverse_iterator to reverse beginning (public member function)
crend	Return const_reverse_iterator to reverse end (public member function)

Capacity:
size	Return size (public member function)
max_size	Return maximum size (public member function)
resize	Change size (public member function)
capacity	Return size of allocated storage capacity (public member function)
empty	Test whether vector is empty (public member function)
reserve	Request a change in capacity (public member function)
shrink_to_fit	Shrink to fit (public member function)

Element access:
operator[]	Access element (public member function)
at	Access element (public member function)
front	Access first element (public member function)
back	Access last element (public member function)
data	Access data (public member function)

Modifiers:
assign	Assign vector content (public member function)
push_back	Add element at the end (public member function)
pop_back	Delete last element (public member function)
insert	Insert elements (public member function)
erase	Erase elements (public member function)
swap	Swap content (public member function)
clear	Clear content (public member function)
emplace	Construct and insert element (public member function)
emplace_back	Construct and insert element at the end (public member function)

Allocator:
get_allocator	Get allocator (public member function)

Non-member function overloads
relational operators	Relational operators for vector (function template)
swap	Exchange contents of vectors (function template)
 */
#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		//______________Member type________________________________________________

		typedef typename T1		first_type;
		typedef typename T2		second_type;

		//______________Member objects________________________________________________

		first_type 	first;
		second_type second;

		//______________constructors and destructors___________________________________

		//default. value initialized
		pair() : first(first_type()), second(second_type())
		{
		}

		//copy / move contructor: initialized with pr object
		//pr: another pair object
		template <class U, class V>
		pair(const pair<U, V> &pr): first(pr.first), second(pr.second)
		{
		}

		//initialization constructor: Member first is constructed with a and member second with b.
		pair(const first_type &a, const second_type &b): first(a), second(b)
		{
		}
		//______________overload operator______________________________________________

		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return *this;
		}
	};

	//______________non-member functions________________________________________________

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return (ft::pair<T1, T2>(t, u));
	}

	//  Performs the appropriate comparison operation between the pair objects lhs and rhs.
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs==rhs);	
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs<lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs<rhs);
	}
}

#endif
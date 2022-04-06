#include "whatever.hpp"

# define YELLOW "\e[33m"
# define DEFAULT "\e[0m"

int	main(void)
{
	std::cout<<YELLOW<<"------ BASIC -------"<<DEFAULT<<std::endl;
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string	c = "chaine2";
	std::string	d = "chaine1";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout<<std::endl;
	std::cout<<YELLOW<<"------- MORE -------"<<DEFAULT<<std::endl;
	std::cout<<"----- string& ------"<<std::endl;
	std::string	&e = c;
	std::string	&f = d;

	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	std::cout<<std::endl;
	std::cout<<"------- char -------"<<std::endl;
	char	k = 'a';
	char	l = 'z';
	::swap(k, l);
	std::cout << "k = " << k << ", l = " << l << std::endl;
	std::cout << "min( k, l ) = " << ::min( k, l ) << std::endl;
	std::cout << "max( k, l ) = " << ::max( k, l ) << std::endl;

	std::cout<<std::endl;
	std::cout<<"------ float -------"<<std::endl;
	float	g = 2.3f;
	float	h = 4.3f;
	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;

	std::cout<<std::endl;
	std::cout<<"------ double ------"<<std::endl;
	double	i = 3.5;
	double	j = 5.5;
	::swap(i, j);
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min( i, j ) = " << ::min( i, j ) << std::endl;
	std::cout << "max( i, j ) = " << ::max( i, j ) << std::endl;

	std::cout<<std::endl;
	std::cout<<"------ const ------"<<std::endl;
	std::cout << "min( a, b ) = " << ::min( 5, 4 ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( 3.33, 5.55 ) << std::endl;
	return (0);
}

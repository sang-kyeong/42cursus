#include <iostream>
#include <stdint.h>
#include "Data.hpp"

uintptr_t	serialize ( Data * ptr );
Data *	deserialize ( uintptr_t raw );
void	print_data( Data * ptr );

int	main ( void )
{
	Data data_org;
	data_org.coalition_point = 0;
	data_org.wallet = 176;
	data_org.evaluation_point = 10;
	std::cout << "** Original Data **" << std::endl;
	print_data(&data_org);

	std::cout << std::endl;

	Data *data_con = deserialize(serialize(&data_org));
	std::cout << "** Converted Data **" << std::endl;
	print_data(data_con);

	// uintptr_t	tmp1 = static_cast<uintptr_t>(&data_org); // error
	// uintptr_t	tmp2 = dynamic_cast<uintptr_t>(&data_org); // error
	return 0;
}

uintptr_t	serialize ( Data * ptr )
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *	deserialize ( uintptr_t raw )
{
	return reinterpret_cast<Data *>(raw);
}

void	print_data( Data * ptr )
{
	std::cout
		<< "Coalition Point  : " << ptr->coalition_point << std::endl
		<< "Wallet           : " << ptr->wallet << std::endl
		<< "Evaluation Point : " << ptr->evaluation_point << std::endl;
}
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Color.hpp"

RobotomyRequestForm::RobotomyRequestForm ( void ) : AForm()
{
	std::cout << BLACK << "[RobotomyRequestForm] default constructor" << WHITE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( const std::string target )
 : AForm("Robotomy Request", 72, 45), _target(target)
{
	std::cout << BLACK << "[RobotomyRequestForm] name constructor" << WHITE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm & other )
 : AForm(other), _target(other._target)
{
	std::cout << BLACK << "[RobotomyRequestForm] copy constructor" << WHITE << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm ( void )
{
	std::cout << BLACK << "[RobotomyRequestForm] destructor" << WHITE << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator= ( const RobotomyRequestForm & other )
{
	if (this != &other)
	{
		AForm::operator=(other);
		//this->_target = other._target;
	}
	return *this;
}

#include <chrono>
void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (executor.getGrade() > this->getExecuteRequirement())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::UnsignedException();
	
	// TODO
	std::cout << "[very noisy drilling sound]" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}
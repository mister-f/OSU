/*************************************
 * Name: Andrew Funk
 * Date: 8-16-17
 * Description: Customer.cpp is the class implementation file
 * 				for the 'Customer' class. It has a constructor,
 * 				get fucntions for its member variables, and functions
 * 				to add items to a customer's cart and empty the cart.
 ************************************/

#include <vector>
#include "Customer.hpp"
using std::string;
using std::vector;

/**************************************
 * Description: This is a constructor used to initialize
 * 				a Customer object.
 *************************************/

Customer::Customer(string n, string a, bool pm)
{
	name = n;
	accountID = a;
	premiumMember = pm;
}

string Customer::getAccountID()			//Get function
{
	return accountID;
}

vector<string> Customer::getCart()		//Get function
{
	return cart;
}

/************************************
 * Description: This function adds a product ID code 
 * 				into a Customer's cart using the vector
 * 				member function 'push_back'.
 ***********************************/

void Customer::addProductToCart(string idIn)
{
	cart.push_back(idIn);
}

/************************************
 * Description: Returns true if a customer has premium 
 * 				member status.
 ***********************************/

bool Customer::isPremiumMember()		
{
	return premiumMember;
}

/***********************************
 * Description: emptyCart uses the vector member function
 * 				'clear' to empty a Customer cart.
 **********************************/

void Customer::emptyCart()
{
	cart.clear();
}


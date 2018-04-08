/**************************************
 * Name: Andrew Funk
 * Date: 8-16-17
 * Description: Product.cpp is the class implementation file
 * 				for the 'Product' class. The Product class has 
 * 				get functions for each of its member variables,
 * 				a constructor, and a function to decrease a 
 * 				Product's quantity.
 *************************************/

#include "Product.hpp"
#include <string>
using std::string;

/***************************************
 * Description: This is a constructor used to initialize
 * 				a Product object.
 **************************************/

Product::Product(string id, string t, string d, double p, int qa)
{
	idCode = id;
	title = t;
	description = d;
	price = p;
	quantityAvailable = qa;
}

string Product::getIdCode()				//Get function
{
	return idCode;
}

string Product::getTitle()				//Get function
{
	return title;
}

string Product::getDescription()		//Get function
{
	return description;
}

double Product::getPrice()				//Get function
{
	return price;
}

int Product::getQuantityAvailable()		//Get function
{
	return quantityAvailable;
}

/**************************************
 * Description: This fucntion decreases the quantity 
 * 				of a product by one as long as there are 
 * 				a positive quantity.
 *************************************/

void Product::decreaseQuantity()
{
	if (quantityAvailable > 0)
	{
		quantityAvailable--;
	}
}


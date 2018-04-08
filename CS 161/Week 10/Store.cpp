/********************************
 * Name: Andrew Funk
 * Date: 8-16-17
 * Description: Store.cpp is the class implementation file for
 * 				the 'Store' class. The Store class is able to 
 * 				create an inventory and customer list, search for
 * 				items within those lists, add items to customer's
 * 				carts, and allow a cutomer to check out.
 ********************************/

#include <iostream>
#include <cctype>
#include "Store.hpp"
using std::string;
using std::cout;
using std::endl;

/**********************************
 * Description: This function adds a pointer to a Product
 * 				to the inventory.
 *********************************/

void Store::addProduct(Product* p)
{
	inventory.push_back(p);
}

/*********************************
 * Description: This function adds a pointer to a Customer
 * 				to the member vector.
 ********************************/
void Store::addMember(Customer* c)
{
	members.push_back(c);
}

/*********************************
 * Description: This function checks a product ID against the
 * 				store inventory. If the product is found, a pointer
 * 				to that product is returned, otherwise NULL is 
 * 				returned.
 ********************************/

Product* Store::getProductFromID(string pIDIn)
{
	// Loop through inventory
	for (int i = 0; i < inventory.size(); i++)
	{
		// Check if ID matches any in current inventory element
		if (inventory.at(i)->getIdCode() == pIDIn)
		{
			return inventory.at(i);
		}
	}
	
	// Return NULL if no match found
	return NULL;
}

/*********************************
 * Description: This function checks a member ID against the
 * 				store's saved customers. If the customerer is 
 * 				found, a pointer to that customer is returned, 
 * 				otherwise NULL is returned.
 ********************************/

Customer* Store::getMemberFromID(string mIDIn)
{
	// Loop through members
	for (int i = 0; i < members.size(); i++)
	{
		// Check if ID matches current member element
		if (members.at(i)->getAccountID() == mIDIn)
		{
			return members.at(i);
		}
	}
	
	// Return NULL if no match found
	return NULL;
}

/**********************************
 * Description: This function takes a string and uses it to
 * 				search through the item titles and descriptions
 * 				that are in inventory. The case of the first letter
 * 				in the search term does not affect the search. If 
 * 				a match is found, the item info is printed.
 *********************************/

void Store::productSearch(string str)
{
	string lowerString = str;
	string upperString = str;	

	// Create a search string with first letter in lower case
	if (isupper(str[0]))
	{
		lowerString = "";
		lowerString += tolower(str[0]);
		for (int i = 1; i < str.length(); i++)
		{
			lowerString += str[i];
		} 
	}
	// Create a search string with first letter in upper case
	else
	{
		upperString = "";
		upperString += toupper(str[0]);
		for (int i = 1; i < str.length(); i++)
		{
			upperString += str[i];
		} 
	}

	// Loop through inventory
	for (int i = 0; i < inventory.size(); i++)
	{
		// Check for any matches in item titles and descriptions
		if (((inventory.at(i)->getTitle()).find(lowerString) != 
				string::npos) || ((inventory.at(i)->
				getDescription()).find(lowerString) != string::npos)
				|| ((inventory.at(i)->getTitle()).find(upperString) != 
				string::npos) || ((inventory.at(i)->
				getDescription()).find(upperString) != string::npos))
		{
			// Print item info if there is a match
			cout << inventory.at(i)->getTitle() << endl << "ID code: ";
			cout << inventory.at(i)->getIdCode() << endl << "price: $";
			cout << inventory.at(i)->getPrice() << endl;
			cout << inventory.at(i)->getDescription() << endl << endl;
		}
	}	
}

/***********************************
 * Description: This function takes a product ID and a customer
 * 				ID. It verifies that both IDs are valid, and if 
 * 				they are and the product also has a positive quantity,
 * 				the product is added to the customer's cart.
 **********************************/

void Store::addProductToMemberCart(string pID, string mID)
{
	// Check if Product exists
	if (getProductFromID(pID) == NULL)
	{
		cout << "Product #" << pID << " not found." << endl;
	}
	// Check if member exists
	else if (getMemberFromID(mID) == NULL)
	{
		cout << "Member #" << mID << " not found." << endl;
	}
	// Check if Product is in stock
	else if (getProductFromID(pID)->getQuantityAvailable() == 0)
	{
		cout << "Sorry, product #" << pID;
		cout << " is currently out of stock." << endl;
	}
	// Add Product to member cart
	else 
	{
		getMemberFromID(mID)->addProductToCart(pID);
	}
}

/************************************
 * Description: This function takes a member ID and performs
 * 				a checkout procedure on the items currently in 
 * 				their cart. It makes sure the cart is not empty, 
 * 				and then prints out each item in the cart. It 
 * 				totals the purchase price and adds shipping if 
 * 				customer is not premium. Finally, the cart is
 * 				emptied after checkout.
 ************************************/

void Store::checkOutMember(string mID)
{
	const double SHIPPING_PCT = 0.07;
	double subtotal = 0;
	double shipping;
	double total;

	// Check if member exists
	if (getMemberFromID(mID) == NULL)
	{
		cout << "Member #" << mID << " not found." << endl;
	}
	// Ensure cart is not empty
	else if (getMemberFromID(mID)->getCart().empty())
	{
		cout << "There are no items in the cart." << endl;
	}	
	// Print out items and total costs
	else
	{
		// Loop through cart
		for (int i = 0; i < (getMemberFromID(mID)->getCart()).size(); i++)
		{
			// If item is in stock, print out ledger, decrease
			// item quantity, and add cost to subtotal
			if (getProductFromID(getMemberFromID(mID)->getCart().at(i))->
				getQuantityAvailable() != 0)
			{
				cout << getProductFromID(getMemberFromID(mID)->
					getCart().at(i))->getTitle();
				cout << " - $" << getProductFromID(getMemberFromID(mID)->
					getCart().at(i))->getPrice();
				cout << endl;
				getProductFromID(getMemberFromID(mID)->
					getCart().at(i))->decreaseQuantity();
				subtotal += getProductFromID(getMemberFromID(mID)->
					getCart().at(i))->getPrice();
			}
			// If item not in stock, notify customer
			else
			{ 
				cout << "Sorry, product #";
				cout << getProductFromID(getMemberFromID(mID)->
					getCart().at(i))->getIdCode() << ", \"";
				cout << getProductFromID(getMemberFromID(mID)->
					getCart().at(i))->getTitle(); 
				cout << "\", is no longer available." << endl;
			}
		}
		
		// Check member premium status, add shipping if not premium
		if (getMemberFromID(mID)->isPremiumMember())
		{
			shipping = 0;
		}
		else
		{
			shipping = subtotal * SHIPPING_PCT;
		}
		
		// Compute total cost
		total = subtotal + shipping;

		cout << "Subtotal: $" << subtotal << endl;
		cout << "Shipping Cost: $" << shipping << endl;
		cout << "Total: $" << total << endl << endl;
		
		// Empty the cart
		getMemberFromID(mID)->emptyCart();
	}	
}


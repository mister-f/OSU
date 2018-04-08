/*******************************
 * Description: main for testing purposes.
 ******************************/

#include "Store.hpp"
#include <string>
#include <vector>
using namespace std;

int main()
{
	Customer andy("andy", "100", false);
	Customer bob("bob", "101", true);
	Customer cindy("cindy", "102", true);

	Product blender("123", "red blender", "sturdy blender perfect for making smoothies and sauces", 350, 4);
	Product balloon("345", "hot air balloon", "fly into the sky in your own balloon - comes in Red, blue or chartreuse", 700, 2);
	Product goat("347", "live goat", "a real live goat to love", 520, 0);

	Store store;
	
	store.addMember(&andy);
	store.addMember(&bob);
	store.addMember(&cindy);
	store.addProduct(&blender);
	store.addProduct(&balloon);
	store.addProduct(&goat);

	store.addProductToMemberCart("123", "100");
	store.addProductToMemberCart("345", "101");
	store.addProductToMemberCart("345", "100");
	store.addProductToMemberCart("345", "100");
	store.addProductToMemberCart("123", "100");

	store.checkOutMember("100");
	store.checkOutMember("101");
	
	store.checkOutMember("109");
	store.productSearch("asdfjkhdf");

	store.addProductToMemberCart("123", "109");
	return 0;
}


#include <iostream>
#include <memory>
#include <cstdlib> //used the c header includes instead of the c++ ones
#include <ctime>   //^
#define HEADS 0;
#define TAILS 1; //added semicolons after heads and tails definitions, also not type safed in any way!

struct Coin {
private:
//	int m_value;
	bool is_heads;
public:

	Coin() {
		srand(time(NULL)); //never utilized also in the constructor, why
	}

//	int get_value() {				//never fuckin' used lmao
//		return this->m_value;		//      ^      ^
//	}								//     ^     ^
									//    ^    ^
//	int set_value(int value) {		//   ^   ^
//		this->m_value = value;		//  ^  ^
//	}								// ^ ^

	int is_heads() {
		if (is_heads == true) { // added a conditional to the if statement
			return HEADS;
		}
		else					// added an else so that it doesn't just always return tails.
		{
			return TAILS;
		}
	}
	void set_heads(bool is_heads) { //fixed the int to bool
		this->is_heads = is_heads;
	}
};

class Flipper {
	Coin * m_coin;
public:
	Flipper(Coin * coin) {
		m_coin = coin;
	}
	~Flipper() {
		delete(m_coin);
	}
	void flip() {
		int r = rand() % 10;
		this->m_coin->set_heads(r);
	}
};

int main() {
	std::shared_ptr<Coin> coin = std::make_shared<Coin>();
	Flipper * flipper = new Flipper(coin.get()); 
	//gets the raw pointer that the pointer is using, that is freed using the destructer. 
	//Basically it'll try to delete what the shared pointer is pointing at. You cannot 
	//communicated that you actually deleted it. DONT TRY TO MANAGE THE SHARED POINTER. 
	//LET IT MANAGE ITSELF
	flipper->flip();
	std::cout << coin -> Coin::is_heads() << std::endl;
}

//modern c++ doesn't like raw pointers because there are no checks and balances around
//pointers to tell if it is a valid values.
//if a pointer is set to a null pointer you can assume it was deleted
//otherwise it is impossible to know.

//it's impossible to write memory safe code if you allocated to the heap.

//compile for c++ 14 if at all possible.
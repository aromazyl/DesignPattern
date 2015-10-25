#include "SimplePizzaFactory.h"

int main() {
	std::shared_ptr<factory::PizzaStore> pizzaStore;
	pizzaStore.reset(new factory::ChicaGoPizzaStore);
	pizzaStore->orderPizza("CheesePizza");
	pizzaStore->orderPizza("ClamPizza");
	pizzaStore->orderPizza("VeglePizza");
	pizzaStore.reset(new factory::NYPizzaStore);
	pizzaStore->orderPizza("CheesePizza");
	pizzaStore->orderPizza("ClamPizza");
	pizzaStore->orderPizza("VeglePizza");
	return 0;
}

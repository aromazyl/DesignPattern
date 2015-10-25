#pragma once

#include <iostream>
#include <memory>

namespace factory {

class Pizza {
	public:
		virtual void prepare() = 0;
		virtual void bake() = 0;
		virtual void cut() = 0;
		// virtual void box() = 0;
};

class ChicaGoCheesePizza : public Pizza {
	public:
		virtual void prepare() {
			std::cout << "prepare ChicaGoCheesePizza\n";
		}
		virtual void bake() {
			std::cout << "bake ChicaGoCheesePizza\n";
		}
		virtual void cut() {
			std::cout << "cut ChicaGoCheesePizza\n";
		}
};

class ChicaGoVeglePizza : public Pizza {
	public:
		virtual void prepare() {
			std::cout << "prepare ChicaGoVeglePizza\n";
		}
		virtual void bake() {
			std::cout << "bake ChicaGoVeglePizza\n";
		}
		virtual void cut() {
			std::cout << "cut ChicaGoVeglePizza\n";
		}
};

class ChicaGoClamPizza : public Pizza {
	public:
		virtual void prepare() {
			std::cout << "prepare ChicaGoClamPizza\n";
		}
		virtual void bake() {
			std::cout << "bake ChicaGoClamPizza\n";
		}
		virtual void cut() {
			std::cout << "cut ChicaGoClamPizza\n";
		}
};

class NYCheesePizza : public Pizza {
	public:
		virtual void prepare() {
			std::cout << "prepare NYCheesePizza\n";
		}
		virtual void bake() {
			std::cout << "bake NYCheesePizza\n";
		}
		virtual void cut() {
			std::cout << "cut NYCheesePizza\n";
		}
};

class NYVeglePizza : public Pizza {
	public:
		virtual void prepare() {
			std::cout << "prepare NYVeglePizza\n";
		}
		virtual void bake() {
			std::cout << "bake NYVeglePizza\n";
		}
		virtual void cut() {
			std::cout << "cut NYVeglePizza\n";
		}
};

class NYClamPizza : public Pizza {
	public:
		virtual void prepare() {
			std::cout << "prepare NYClamPizza\n";
		}
		virtual void bake() {
			std::cout << "bake NYClamPizza\n";
		}
		virtual void cut() {
			std::cout << "cut NYClamPizza\n";
		}
};

class PizzaFactory {
	public:
		virtual std::shared_ptr<Pizza> CreatePizza(const std::string& pizzaName) const = 0;
};

class ChicaGoPizzaFactory : public PizzaFactory {
	public:
		virtual std::shared_ptr<Pizza> CreatePizza(const std::string& pizzaName) const {
			std::shared_ptr<Pizza> ret;
			if (pizzaName == "ClamPizza")
				ret.reset(new ChicaGoClamPizza);
			if (pizzaName == "CheesePizza")
				ret.reset(new ChicaGoCheesePizza);
			if (pizzaName == "VeglePizza")
				ret.reset(new ChicaGoVeglePizza);
			return ret;
		}
};

class NYPizzaFactory : public PizzaFactory {
	public:
		virtual std::shared_ptr<Pizza> CreatePizza(const std::string& pizzaName) const {
			std::shared_ptr<Pizza> ret;
			if (pizzaName == "ClamPizza")
				ret.reset(new NYClamPizza);
			if (pizzaName == "CheesePizza")
				ret.reset(new NYCheesePizza);
			if (pizzaName == "VeglePizza")
				ret.reset(new NYVeglePizza);
			return ret;
		}
};

class PizzaStore {
	public:	
		virtual void SetFactory(std::shared_ptr<PizzaFactory> factory) {
			this->factory_ = factory;
		}
		virtual std::shared_ptr<Pizza> orderPizza(const std::string& pizzaName) const = 0;
	protected:
		std::shared_ptr<PizzaFactory> factory_;
};

class ChicaGoPizzaStore : public PizzaStore {
	public:
		ChicaGoPizzaStore() {
			this->SetFactory(std::shared_ptr<PizzaFactory>(new ChicaGoPizzaFactory));
		}
		virtual std::shared_ptr<Pizza> orderPizza(const std::string& pizzaName) const {
			auto pizza = factory_->CreatePizza(pizzaName);
			pizza->prepare();
			pizza->bake();
			pizza->cut();
			// pizza->box();
			return pizza;
		}
};

class NYPizzaStore : public PizzaStore {
	public:
		NYPizzaStore() {
			this->SetFactory(std::shared_ptr<PizzaFactory>(new NYPizzaFactory));
		}
		virtual std::shared_ptr<Pizza> orderPizza(const std::string& pizzaName) const {
			auto pizza = factory_->CreatePizza(pizzaName);
			pizza->prepare();
			pizza->bake();
			pizza->cut();
			// pizza->box();
			return pizza;
		}
};

}

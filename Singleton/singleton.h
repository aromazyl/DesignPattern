#pragma once

#include <memory>
#include <mutex>

class Singleton {
	public:
		static Singleton* GetInstance() {
			if (!instance_) {
				std::lock_guard<std::mutex> guard(lock_);
				if (!instance_) {
					instance_ = new Singleton;
				}
			}
			return instance_;
		}
	private:
		class Garbage {
			public:
				Garbage() {}
				~Garbage() {
					if (instance_)
						delete Singleton::instance_;
				}
		};
		static Garbage garbage;
		Singleton() {}
		~Singleton() {}
		static std::mutex lock_;
		static Singleton* instance_;
};

Singleton* Singleton::instance_ = NULL;
std::mutex Singleton::lock_;

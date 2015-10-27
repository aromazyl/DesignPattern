#pragma once

#include <memory>
#include <iostream>

class Light {
	public:
		void on() {
			state = true;
			std::cout << "turn light on\n";
		}
		void off() {
			state = false;
			std::cout << "turn light off\n";
		}
	private:
		bool state_;
};

class Command {
	public:
		virtual void excute() = 0;
};

class NoCommand : public Command {
	public:
		void excute() {}
};

class LightOnCommand : public Command {
	public:
		void LightOnCommand(std::shared_ptr<Light> light) {
			light_ = light;
		}

		void excute() {
			light->on();
		}
	private:
		std::shared_ptr<Light> light_;
};

class LightOffCommand : public Command {
	public:
		void LightOffCommand(std::shared_ptr<Light> light) {
			light_ = light;
		}

		void excute() {
			light->off();
		}
	private:
		std::shared_ptr<Light> light_;
};

class SimpleRemoteControl {
	public:
		void setCommand(std::shared_ptr<Command> command) {
			command_ = command;
		}
		void buttonWasPressed() {
			command_->excute();
		}
	private:
		std::shared_ptr<Command> command_;
};

class RemoteControl {
	public:
		RemoteControl() {
			onCommands_.resize(7);
			offCommands_.resize(7);
		}

		void setCommand(int slot, std::shared_ptr<Command> onCommand, std::shared_ptr<Command> offCommand) {
			onCommands_[slot] = onCommand;
			offCommands_[slot] = offCommand;
		}

		void onButtonWasPushed(int slot) {
			onCommands[slot]->execute();
		}

		void offButtonWasPushed(int slot) {
			offCommands[slot]->execute();
		}
		
		std::string toString() {
			return "";
		}

	private:
		std::vector<std::shared_ptr<Command>> onCommands_;
		std::vector<std::shared_ptr<Command>> offCommands_;
};

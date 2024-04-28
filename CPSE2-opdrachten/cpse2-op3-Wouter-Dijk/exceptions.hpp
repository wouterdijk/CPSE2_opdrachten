#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class UnknownFactoryException : public std::exception {
public:
	UnknownFactoryException( const std::string & name ):
		s{ std::string{ "Unknown Object [" + name + "]" }}
		{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class UnknownColorException : public std::exception {
public:
	UnknownColorException( const std::string & color ):
		s{ std::string{ "Unknown color [" + color + "]" }}
		{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class NotLineException : public std::exception {
public:
	NotLineException( const std::string & number ):
		s{ std::string{ "Emptyline [" + number + "]" }}
		{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class NotNumberException : public std::exception {
public:
	NotNumberException( const std::string & text ):
		s{ std::string{ "Not a number [" + text + "]" }}
		{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class NoPictureFileException : public std::exception {
public:
	NoPictureFileException( const std::string & file ):
		s{ std::string{ "No Picture file [" + file + "]" }}
		{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

#endif
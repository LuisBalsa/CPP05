# CPP Module 05

This project is part of the 42 School C++ modules. It covers inheritance, polymorphism, abstract classes, and exception handling in C++.

## Structure

The project is divided into several exercises (`ex00`, `ex01`, `ex02`, `ex03`), each focusing on different aspects of C++ class design and functionality:

- **ex00**: Basic `Bureaucrat` class with grade validation and exception handling.
- **ex01**: Introduction of the `Form` class, which can be signed by a `Bureaucrat`.
- **ex02**: Abstract `AForm` class and concrete forms (`PresidentialPardonForm`, `RobotomyRequestForm`, `ShrubberyCreationForm`) with execution logic.
- **ex03**: Adds the `Intern` class, capable of creating forms dynamically.

## How to Build

Each exercise has its own `Makefile`. To compile an exercise, navigate to its directory and run:

```sh
make
```

This will build the executable named `bureaucrat`.

## Usage

Run the executable after building:

```sh
./bureaucrat
```

Follow the on-screen instructions and observe the output for each test case.

## Requirements

- C++98 standard
- Make
- g++ or clang++

## Notes

- Exception handling is used for grade validation and form signing/execution.
- The project demonstrates the use of abstract classes and pure virtual functions.
- The `Intern` class in `ex03` can create different types of forms based on input.

# NAMESPACE


_**Using namespace std**_

In C++ codes, you may have seen cout being used instead of std::cout. 
Both name the same object: the first one uses its unqualified name (cout), while the second qualifies it directly within the namespace std (as std::cout).

cout is part of the standard library, and all the elements in the standard C++ library are declared within what is called a namespace: the namespace std.

In order to refer to the elements in the std namespace a program shall either qualify each and every use of elements of the library (as we have done by prefixing cout with std::), or introduce visibility of its components.

The most typical way to introduce visibility of these components is by means of using declarations:
		```C++
		using namespace std;
		```

The above declaration allows all elements in the std namespace to be accessed in an unqualified manner (without the std:: prefix).


## Using NAMESPACEs
-----------------
C++ provides a single global space. This global namespace can be sub divided into more manageable pieces using the *namespace* feature of C++.
Thus the global scope is divided into sub-scopes, each one with its own name.

_Format_:-
```
namespace <identifier>
{
	<entities>
}
```
* Declarations that fall outside all the namespaces are still members of the global namespace
* **Extension-Namespace-Definition**:- A namespace definition can be continued over multiple header files like this:
	```C++
	// File1.h
	namespace myFile
	{
	    <entities>
	}
	
	// File2.h
	namespace myFile
	{
	
	}
	```
* __Namespace-alias__:- Giving an alternate name for a namespace.
	```C++
	namespace low_and_high_density
	{
		class Density
		{
		};
	}
	namespace lahd = low_and_high_density
	```
* A namespace definition can only appear at the global scope or within another namespace definition.
  For example, the following code is wrong.
  ```C++
  int main()
  {
  	namespace Local	// Error
	{
	}
	return 0;
  }
  ```
* There are 2 ways to refer to a name within a namespace:
** By including the namespace identifier followed by the scope resolution operator.
   With this, only specific members of the namespace can be introduced.
** By introducing the entire namespace by the use of "using" directive	
		```C++
		using namespace *<namespace_name>*
		```
   Doing so will allow the programmer to call functions from within the namespace without having to specify the namespace of the function while in the current scope.

	(_Preferred way of usage is scope resolution._)
	
	

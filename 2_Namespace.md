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


For instance, if you had a program that connected to the Internet, you might have a namespace to handle all connection functions: 
	```C++
	namespace net_connect
	{
	  int make_connection();
	  int test_connection();
	  //so forth...
	}
	```
	
You can then refer to functions that are part of a namespace by prefixing the function with the namespace name followed by the scope operator -- ::. For instance,
	```C++
	net_connect::make_connection()
	```
	
By enabling this program structure, C++ makes it easier for you to divide up a program into groups that each perform their own separate functions, in the same way that classes or structs simplify object oriented design. 
But namespaces, unlike classes, do not require instantiation; you do not need an object to use a specific namespace. You only need to prefix the function you wish to call with namespace_name:: -- similar to how you would call a static member function of a class. 


We can use the namespace in 2 different ways:
	1. By including the namespace identifier followed by the scope resolution operator.
		With this, only specific members of the namespace can be introduced.
	2. By introducing the entire namespace by the use of "using" directive
		```C++
		using namespace *<namespace_name>*
		```
		Doing so will allow the programmer to call functions from within the namespace without having to specify the namespace of the function while in the current scope.







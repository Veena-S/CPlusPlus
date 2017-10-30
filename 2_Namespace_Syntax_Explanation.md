# 1. Named Namespace Definition
*Syntax*:-
```C++
namespace nsName { <declarations> }
```
Named namespace definition for the namespace nsName.
```
inline(optional) namespace attr(optional) identifier{ namespace-body }
```
*inline* - 	If present, makes this an inline namespace (see below).
            Cannot appear on the *extension-namespace-definition* if the original-namespace-definition did not use inline.
            
*attr* -  Since C++17. Optional sequence of any number of attributes. 

*identifier* - Either original or extension or nested namespace identifier. Identified in the following ways:
   1. Either a previously unused identifier, in which case this is the *original-namespace-definition* or
   2. the name of a namespace, in which case this is *extension-namespace-definition* or
   3. A sequence of enclosing namespace specifiers separated by ::, ending with *identifier* in which case this is a *nested-namespace-definition*. (Since C++17)

*namespace-body* - possibly empty sequence of declarations of any kind (including class and function definitions as well as nested namespaces)

* To reopen an existing namespace (i.e., to be an extension-namespace-definition), the lookup for the identifier used in the namespace definition must resolve to a namespace name (*not a namespace alias*), that was declared as a member of the enclosing namespace or of an inline namespace within an enclosing namespace.

* The namespace-body defines a namespace scope, which affects name lookup.

* All names introduced by the declarations that appear within namespace-body (including nested namespace definitions) become members of the namespace identifier, whether this namespace definition is the original namespace definition (which introduced identifier), or an extension namespace definition (which "reopened" the already defined namespace).

* A namespace member that was declared within a namespace body may be defined or redeclared outside of it using explicit qualification.

# 2. Inline Namespace definition (*Since C++ 11* )
_Syntax_:-
```C++
inline namespace nsName { <declarations> }
```

# 3. Unnamed Namespace Definition
_Syntax_:-
```C++
namespace { <declarations> }
```

# 4. Qualified Name lookup
_Syntax_:-
```C++
nsName::name
```
# 5. using-directive
_Syntax_:-
```C++
using namespace nsName;
```

# 6. using-declaration
_Syntax_:-
```C++
using nsName::name;
```


# 7. Namespace Alias
_Syntax_:-
```C++
namespace name = qualified_namespace;
```


# 8. Nested Namespace definition (*Since C++ 17*)
_Syntax_:-
```C++
namespace nsName::name
```

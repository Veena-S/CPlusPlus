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
```C++
namespace Q
{
    namespace V         // V is a member of Q and is fully defined in Q.
    {
            // namespace Q::V{ C++17 alternative to the above lines
            class C     // C is a member of V and is fully defined in V
            {
                void m();           // C::m is only declared
            };
            
            void f();               // f is a member of V, but is only declaration is here.
            
    } // namespace V ends
    
    void V::f()         // Definition of V's member f, outside of V
                        // f's enclosing namespaces are still the global namespace, Q, and Q::V
    {
            extern void h();        // This declares ::Q::V::h
    }
    void V::C::m() // definition of V::C::m outside of the namespace (and the class body)
                  // enclosing namespaces are the global namespace, Q, and Q::V
    {
    }
} // Namespace Q ends
```

* Out of namespace definitions and redeclarations are only allowed after the point of declaration, only at namespace scope, and only in namespaces that enclose the original namespace (including global namespace) and **they must use qualified-id syntax (since c++14)**
```C++
namespace Q
{
    namespace V    // original-namespace-definition for V
    {
        void f();    // declaration of Q::V::f()
    }       // V ends
    
    void v::f() // Defininf f, outside V. OK
    {
    }
    
    void V::g() { } // ERROR: g is not yet a member of V.
    
    namespace V   // Extension-namespace-definition of V
    {
        void g();    // declaration of Q::V::g
    } // V ends
        
} // Q ends

namespace R   // Not an enclosing namespace for Q
{
    void Q::V::g() {} // ERROR: Cannot define Q::V::g() inside R
}  // R ends

void Q::V::g() {} // OK: global namespace encloses Q
```

* Names introduced by friend declarations within a non-local class X become members of the innermost enclosing namespace of X, but they do not become visible to lookup (neither unqualified nor qualified) unless a matching declaration is provided at namespace scope, either before or after the class definition. Such name may be found through ADL (Argument-Dependent-Lookup) which considers both namespaces and classes.
Only the innermost enclosing namespace is considered by such friend declaration when deciding whether the name would conflict with a previously declared name.

```C++
void h(int);

namespace A
{
    class X
    {
        friend void f(x); // A::f is a friend
        class Y
        {
            friend void g(); // A::g is a friend
            friend void h(int); // A::h is a friend. No conflict with ::h
        }; // class Y ends
    }; // class X ends
    
    // A::f, A::g and A::h are not visible at namespace scope
    // even though they are members of the namespace A
    
    X x;
    void g()   // Definition of A::g
    {
        f(x);   // A::X::f is found through ADL
    }
    
    void f(X) {}       // definition of A::f
    
    void h(int) {}     // definition of A::h
    
    // A::f, A::g and A::h are now visible at namespace scope
    // and they are also friends of A::X and A::X::Y
} // A ends
```


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

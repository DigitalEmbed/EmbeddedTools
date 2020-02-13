//! EmbeddedTools Version 2.0b
/*!
  This code file was written by Jorge Henrique Moreira Santana and is under
  the GNU GPLv3 license. All legal rights are reserved.

  Permissions of this copyleft license are conditioned on making available
  complete source code of licensed works and modifications under the same
  license or the GNU GPLv3. Copyright and license notices must be preserved.
  Contributors provide an express grant of patent rights. However, a larger
  work using the licensed work through interfaces provided by the licensed
  work may be distributed under different terms and without source code for
  the larger work.

  * Permissions:
    -> Commercial use;
    -> Modification;
    -> Distribuition;
    -> Patent Use;
    -> Private Use;

  * Limitations:
    -> Liability;
    -> Warranty;

  * Conditions:
    -> License and copyright notice;
    -> Disclose source;
    -> State changes;
    -> Same license (library);

  For more informations, check the LICENSE document. If you want to use a
  commercial product without having to provide the source code, send an email
  to jorge_henrique_123@hotmail.com to talk.

  Reference: https://gcc.gnu.org/onlinedocs/gcc-3.2/gcc/Function-Attributes.html
*/

#ifndef __ATTRIBUTE_H__
  #define __ATTRIBUTE_H__

  #if defined (__ATTRIBUTE_MACROS_ENABLE__)

    //! Macro: No Return
    /*!
      A few standard library functions, such as abort and exit, cannot return. GCC knows this automatically. Some programs define their own functions that never return. You can declare them noreturn to tell the compiler this fact. The noreturn keyword tells the compiler to assume that fatal cannot return. It can then optimize without regard to what would happen if fatal ever did return. This makes slightly better code. More importantly, it helps avoid spurious warnings of uninitialized variables.
    */
    #define ATTRIBUTE_NO_RETURN __attribute__((noreturn))

    //! Macro: No Inline
    /*!
      This function attribute prevents a function from being considered for inlining.
    */
    #define ATTRIBUTE_NO_INLINE __attribute__((noinline))

    //! Macro: Always Inline
    /*!
      Generally, functions are not inlined unless optimization is specified. For functions declared inline, this attribute inlines the function even if no optimization level was specified.
    */
    #define ATTRIBUTE_ALWAYS_INLINE __attribute__((always_inline))

    //! Macro: Pure
    /*!
      Many functions have no effects except the return value and their return value depends only on the parameters and/or global variables. Such a function can be subject to common subexpression elimination and loop optimization just as an arithmetic operator would be. These functions should be declared with the attribute pure. Some of common examples of pure functions are strlen or memcmp. Interesting non-pure functions are functions with infinite loops or those depending on volatile memory or other system resource, that may change between two consecutive calls (such as feof in a multi-threading environment).
    */
    #define ATTRIBUTE_PURE __attribute__((pure))

    //! Macro: Const
    /*!
      Many functions do not examine any values except their arguments, and have no effects except the return value. Basically this is just slightly more strict class than the pure attribute above, since function is not allowed to read global memory. Note that a function that has pointer arguments and examines the data pointed to must not be declared const. Likewise, a function that calls a non-const function usually must not be const. It does not make sense for a const function to return void.
    */
    #define ATTRIBUTE_CONST __attribute__((const))
    
    //! Macro: Format
    /*!
      This specifies that a function takes printf, scanf, strftime or strfmon style arguments which should be type-checked against a format string. The format attribute allows you to identify your own functions which take format strings as arguments, so that GCC can check the calls to these functions for errors. The compiler always (unless -ffreestanding is used) checks formats for the standard library functions printf, fprintf, sprintf, scanf, fscanf, sscanf, strftime, vprintf, vfprintf and vsprintf whenever such warnings are requested (using -Wformat), so there is no need to modify the header file stdio.h.
      \param ioArchetype Determines how the format string is interpreted, and should be printf, scanf, strftime or strfmon. (You can also use __printf__, __scanf__, __strftime__ or __strfmon__).
      \param uiStringIndex Specifies which argument is the format string argument (starting from 1).
      \param uiFirstToCheck Is the number of the first argument to check against the format string. For functions where the arguments are not available to be checked (such as vprintf), specify the third parameter as zero. In this case the compiler only checks the format string for consistency. For strftime formats, this parameter is required to be zero.
    */
    #define ATTRIBUTE_FORMAT(ioArchetype, uiStringIndex, uiFirstToCheck) __attribute__((format(ioArchetype, uiStringIndex, uiFirstToCheck)))
    
    //! Macro: Format Arg
    /*!
      This attribute specifies that a function takes a format string for a printf, scanf, strftime or strfmon style function and modifies it (for example, to translate it into another language), so the result can be passed to a printf, scanf, strftime or strfmon style function (with the remaining arguments to the format function the same as they would have been for the unmodified string).
      \param uiStringIndex Specifies which argument is the format string argument (starting from 1).
    */
    #define ATTRIBUTE_FORMAT_ARG(uiStringIndex) __attribute__((format_arg(uiStringIndex)))
    
    //! Macro: No Instrument Function
    /*!
      If -finstrument-functions is given, profiling function calls will be generated at entry and exit of most user-compiled functions. Functions with this attribute will not be so instrumented.
    */
    #define ATTRIBUTE_NO_INSTRUMENT_FUNCTION __attribute__((no_instrument_function))
    
    //! Macro: Section Name
    /*!
      Normally, the compiler places the code it generates in the text section. Sometimes, however, you need additional sections, or you need certain particular functions to appear in special sections. The section attribute specifies that a function lives in a particular section.
    */
    #define ATTRIBUTE_SECTION(xSectionName) __attribute__((section(xSectionName)))

    //! Macro: Constructor
    /*!
      This attribute causes the function to be called automatically before execution enters main(). Functions with this attribute are useful for initializing data that will be used implicitly during the execution of the program.
      \param uiPriority This optional attribute is important if you want to force a specific order for constructors.
    */
    #if defined(__PRIORITY_CONSTRUCTOR_DESTRUCTOR_ENABLE__)
      #define ATTRIBUTE_CONSTRUCTOR(uiPriority) __attribute__((constructor(uiPriority)))
    #else
      #define ATTRIBUTE_CONSTRUCTOR(uiPriority) __attribute__((constructor))
    #endif

    //! Macro: Destructor
    /*!
      This attribute causes the function to be called automatically after main() has completed or exit() has been called. Functions with this attribute are useful for initializing data that will be used implicitly during the execution of the program.
      \param uiPriority This optional attribute is important if you want to force a specific order for destructors.
    */
    #if defined(__PRIORITY_CONSTRUCTOR_DESTRUCTOR_ENABLE__)
      #define ATTRIBUTE_DESTRUCTOR(uiPriority) __attribute__((destructor(uiPriority)))
    #else
      #define ATTRIBUTE_DESTRUCTOR(uiPriority) __attribute__((destructor))
    #endif

    //! Macro: Unused
    /*!
      This attribute, attached to a function, means that the function is meant to be possibly unused. GCC will not produce a warning for this function. GNU C++ does not currently support this attribute as definitions without parameters are valid in C++.
    */
    #define ATTRIBUTE_UNUSED __attribute__((unused))
    
    //! Macro: Used
    /*!
      This attribute, attached to a function, means that code must be emitted for the function even if it appears that the function is not referenced. This is useful, for example, when the function is referenced only in inline assembly.
    */
    #define ATTRIBUTE_USED __attribute__((used))
    
    //! Macro: Deprecated
    /*!
      The deprecated attribute results in a warning if the function is used anywhere in the source file. This is useful when identifying functions that are expected to be removed in a future version of a program. The warning also includes the location of the declaration of the deprecated function, to enable users to easily find further information about why the function is deprecated, or what they should do instead.
    */
    #define ATTRIBUTE_DEPRECATED __attribute__((deprecated))
    
    //! Macro: Weak
    /*!
      The weak attribute causes the declaration to be emitted as a weak symbol rather than a global. This is primarily useful in defining library functions which can be overridden in user code, though it can also be used with non-function declarations.
    */
    #define ATTRIBUTE_WEAK __attribute__((weak))
    
    //! Macro: Memory Allocation
    /*!
      The malloc attribute is used to tell the compiler that a function may be treated as if it were the malloc function. The compiler assumes that calls to malloc result in a pointers that cannot alias anything. This will often improve optimization.
    */
    #define ATTRIBUTE_MALLOC __attribute__((malloc))
    
    //! Macro: Alias
    /*!
      The alias attribute causes the declaration to be emitted as an alias for another symbol, which must be specified.
    */
    #define ATTRIBUTE_ALIAS(xTarget) __attribute__((alias(#xTarget)))
  
  #endif
#endif
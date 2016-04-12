/*
* This file is part of Lua API++ library (https://github.com/OldFisher/lua-api-pp)
* distributed under MIT License (http://opensource.org/licenses/MIT).
* See license.txt for details.
* (c) 2014 OldFisher
*/

#ifndef LUAPP_HPP_INCLUDED
#define LUAPP_HPP_INCLUDED

//! @file
//! @brief Main include file for Lua API++ library (no other files need to be included).

#include "luapp_config.hxx"
#include "luapp_basetypes.hxx"
#include "luapp_state.hxx"
#include "luapp_value.hxx"
#include "luapp_lazy.hxx"
#include "luapp_indexer.hxx"
#include "luapp_call.hxx"
#include "luapp_closure.hxx"
#include "luapp_operations.hxx"
#include "luapp_valueset.hxx"
#include "luapp_table.hxx"
#include "luapp_context.hxx"
#include "luapp_wrap.hxx"
#include "luapp_impl.hxx"


//! @def LUAPP_USERDATA(type, class_name)
//! @brief Userdata type to name string binder.
//! @param type Userdata type being registered. Must be copyable or moveable.
//! @param class_name String identifier.
//! @details Use this macro to register some type as a userdata type. After registration this type will be recognised as userdata and can be
//! implicitly converted to Lua value and explicitly converted to from Lua value. The storage for the object is allocated by Lua.
//! @note After registering userdata type with this macro, do not forget to assign its metatable during environment setup. For types that require destruction be sure to set <code>__gc</code> metamethod.
//! @note Use this macro outside of namespaces, functions, classes etc.
#define LUAPP_USERDATA(type, class_name) namespace lua { template <> struct UserData<type> {typedef void enabled; static constexpr const char* const classname = class_name;}; }


//! @def LUAPP_ARG_CONVERT(src_type, body)
//! @brief Argument conversion binder.
//! @param src_type Native type of function argument. Must not be supported native type or userdata.
//! @param body The body of conversion function with curved braces.
//! @details This macro is used to define a conversion routine to transform Lua value into native value that will be used as an argument to a wrapped function
//! passed to @ref lua::Context::wrap "Context::wrap" function.\n
//! Provide the type for the argument to be converted to from Lua value and the body for function receiving <code>const Valref& val</code> parameter and returning <code>src_type</code>. Example:
//! @code{.cpp}
//! void arbitraryFunction(const std::vector<char>& x, int y);
//! LUAPP_ARG_CONVERT(std::vector<char>, {const char* arg = val; return std::vector<char>(arg, arg + strlen(arg));} )
//! @endcode
//! @note Use this macro outside of namespaces, functions, classes etc.
//! @see lua::Context::wrap
#define LUAPP_ARG_CONVERT(src_type, body) namespace lua { namespace _ { namespace wrap { template<> inline src_type argCvt<src_type>(const ::lua::Valref& val) body }}}



//! @def LUAPP_RV_CONVERT(rv_type, body)
//! @brief Return value conversion binder.
//! @param rv_type Native type of function argument. Must not be supported native type or userdata.
//! @param body The body of conversion function with curved braces.
//! @details This macro is used to define a conversion routine to transform native value returned by arbitrary C++ function into a Lua value that will be returned by wrapper function created by
//! @ref lua::Context::wrap "Context::wrap" function.\n
//! Provide the type for the return value to be converted to from Lua value and the body for function receiving arguments <code>(rv_type&& val, lua::Context& context</code> parameter. Example:
//! @code{.cpp}
//! std::vector<char> otherArbitraryFunction();
//! LUAPP_RV_CONVERT(std::vector<char>, {return context.ret(val.data());}
//! @endcode
//! @note Use this macro outside of namespaces, functions, classes etc.
//! @see lua::Context::wrap
#define LUAPP_RV_CONVERT(rv_type, body) namespace lua { namespace _ { namespace wrap { template<> inline lua::Retval rvCvt<rv_type>(rv_type val, lua::Context& context) body }}}


#ifdef LUAPP_HEADER_ONLY
#define LUAPP_HEADER_ONLY_FLAG
#include "luapp_impl.cpp"
#undef LUAPP_HEADER_ONLY_FLAG
#endif


#endif // LUAPP_HPP_INCLUDED

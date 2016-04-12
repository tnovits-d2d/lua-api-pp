/*
* This file is part of Lua API++ library (https://github.com/OldFisher/lua-api-pp)
* distributed under MIT License (http://opensource.org/licenses/MIT).
* See license.txt for details.
* (c) 2014 OldFisher
*/

#ifndef LUA_CONFIG_HXX_INCLUDED
#define LUA_CONFIG_HXX_INCLUDED


#ifdef LUAPP_COMPATIBILITY_V51
#define LUAPP_API_VERSION 51
#endif

#ifdef LUAPP_COMPATIBILITY_V52
#define LUAPP_API_VERSION 52
#endif

#ifdef LUAPP_COMPATIBILITY_V53
#define LUAPP_API_VERSION 53
#endif

#ifndef LUAPP_API_VERSION
#define LUAPP_API_VERSION 53
#endif


#ifdef LUAPP_NONDISCARDABLE_ALL
#define LUAPP_NONDISCARDABLE_INDEX
#define LUAPP_NONDISCARDABLE_ARITHMETICS
#define LUAPP_NONDISCARDABLE_CONCAT
#endif	// LUAPP_NONDISCARDABLE_ALL


#endif // LUA_CONFIG_HXX_INCLUDED

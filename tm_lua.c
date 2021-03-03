// zig cc -shared -o tm_lua.dll tm_lua.c lua54.lib -I %TM_DINO_SDK_DIR%/headers

#include "lua/lauxlib.h"
#include "lua/lua.h"
#include "lua/lualib.h"

#include <foundation/api_registry.h>
#include <foundation/log.h>

TM_DLL_EXPORT void tm_load_plugin(struct tm_api_registry_api* reg, bool load)
{
    struct tm_logger_api* tm_logger_api = reg->get(TM_LOGGER_API_NAME);

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dostring(L, "return math.sin(math.pi * 30 / 180)");
    const lua_Number res = luaL_optnumber(L, -1, 0);
    TM_LOG("sin(30°) = %f\n", res);
}
# tm_lua

Sample project that shows how to bind an external library to The Machinery.

`tm_lua.c` is a tiny C file that implements The Machinery's `tm_load_plugin()` interface. It loads
`lua54.dll` using `lua54.lib` and upon load of the plugin, it evaluates the string
`return sin(math.pi * 30 / 18)` in Lua and logs the result using `TM_LOG()`.

To test this plugin in a project, first build `tm_lua.dll` for your current The Machinery version
using:

~~~
zig cc -shared -o tm_lua.dll tm_lua.c lua54.lib -I %TM_DINO_SDK_DIR%/headers
~~~

Then drop both the `tm_lua.dll` and the `lua54.dll` DLLs into the asset
browser of the project, you should see this in the log:

~~~
sin(30°) = 0.500000
~~~

> **Note:** This plugin requires support for helper DLLs in the plugin asset system, which will
> only be available in The Machinery 2021.3 and onwards.
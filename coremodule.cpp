#include <amxmodx.h>
#include <amxhook.h>

#define CORE_MODULE_ID "CoreModule"

bool g_bModuleReady = false;

static cell AMX_NATIVE_CALL n_is_core_module_ready(AMX *amx, cell *params) {
    return g_bModuleReady;
}

void OnAmxxModuleInit() {
    MF_RegisterModule(CORE_MODULE_ID);
    MF_RegisterNative("is_core_module_ready", n_is_core_module_ready);

    g_bModuleReady = true;
    // log_amx("Core module loaded.");
}
void OnAmxxModuleUnload() {
    g_bModuleReady = false;

    // log_amx("Core module unloaded.");
}

const char* GetPluginAuthors() {
    return "Your Name";
}

const char* GetPluginVersion() {
    return "1.0";
}

const char* GetPluginFile() {
    return "core_module";
}

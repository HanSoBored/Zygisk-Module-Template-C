#include <jni.h>
#include <unistd.h>
#include <android/log.h>
#include "zygisk.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "ZygiskModuleC", __VA_ARGS__)

static void onLoad(struct zygisk_api *api, JNIEnv *env) {
    LOGD("onLoad");
    // You can use api->hookJniNativeMethods, etc. here
}

static void preAppSpecialize(void *impl, struct zygisk_app_specialize_args *args) {
    // struct zygisk_api *api = (struct zygisk_api *)impl;
    LOGD("preAppSpecialize");
}

static void postAppSpecialize(void *impl, const struct zygisk_app_specialize_args *args) {
    LOGD("postAppSpecialize");
}

static void preServerSpecialize(void *impl, struct zygisk_server_specialize_args *args) {
    LOGD("preServerSpecialize");
}

static void postServerSpecialize(void *impl, const struct zygisk_server_specialize_args *args) {
    LOGD("postServerSpecialize");
}

static struct zygisk_module_abi module_abi;

__attribute__((visibility("default")))
void zygisk_module_entry(struct zygisk_api *api, JNIEnv *env) {
    module_abi.api_version = ZYGISK_API_VERSION;
    module_abi.impl = api;
    module_abi.preAppSpecialize = preAppSpecialize;
    module_abi.postAppSpecialize = postAppSpecialize;
    module_abi.preServerSpecialize = preServerSpecialize;
    module_abi.postServerSpecialize = postServerSpecialize;

    if (api->registerModule(api, &module_abi)) {
        onLoad(api, env);
    }
}

__attribute__((visibility("default")))
void zygisk_companion_entry(int client) {
    // Root companion handler
    close(client);
}

#pragma once

#include <Windows.h>
#include "Mono/MonoTypes.hpp"

#define MONO_GET_FN(module, monoType) monoMethods.##monoType = reinterpret_cast<t_##monoType>(GetProcAddress(module, #monoType))
#define MONO_MODULE_NAME "mono-2.0-bdwgc.dll"

class Core final {
public:
    explicit Core() {}

    void Initialize() {
        InitializeMonoMethods();
    }

private:
    void InitializeMonoMethods() {
        const HMODULE hMono = GetModuleHandle(MONO_MODULE_NAME);

        MONO_GET_FN(hMono, mono_class_get_method_from_name);
        MONO_GET_FN(hMono, mono_domain_assembly_open);
        MONO_GET_FN(hMono, mono_assembly_get_image);
        MONO_GET_FN(hMono, mono_get_root_domain);
        MONO_GET_FN(hMono, mono_class_from_name);
        MONO_GET_FN(hMono, mono_compile_method);        
        MONO_GET_FN(hMono, mono_thread_attach);
    }
};

#undef MONO_GET_FN

#pragma once

#include <mono/metadata/threads.h>
#include <mono/metadata/object.h>

typedef MonoMethod* (*t_mono_class_get_method_from_name)(MonoClass* klass, const char* name, int paramsCount);
typedef MonoClass* (*t_mono_class_from_name)(MonoImage* image, const char* nmspace, const char* name);
typedef MonoAssembly* (*t_mono_domain_assembly_open)(MonoDomain* domain, const char* name);
typedef MonoImage* (*t_mono_assembly_get_image)(MonoAssembly* assembly);
typedef MonoThread* (*t_mono_thread_attach)(MonoDomain* domain);
typedef void* (*t_mono_compile_method)(MonoMethod* mtd);
typedef MonoDomain* (*t_mono_get_root_domain)();

#define MONO_DEFINE_FN_FIELD(fn) t_##fn fn

struct {
    MONO_DEFINE_FN_FIELD(mono_class_get_method_from_name);
    MONO_DEFINE_FN_FIELD(mono_domain_assembly_open);
    MONO_DEFINE_FN_FIELD(mono_assembly_get_image);
    MONO_DEFINE_FN_FIELD(mono_class_from_name);
    MONO_DEFINE_FN_FIELD(mono_get_root_domain);
    MONO_DEFINE_FN_FIELD(mono_compile_method);
    MONO_DEFINE_FN_FIELD(mono_thread_attach);
} monoMethods;


#undef MONO_DEFINE_FN_FIELD
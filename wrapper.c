#include "vendor/janet/build/janet.h"

JanetType janet_sys_type(Janet x) { return janet_type(x); }
int janet_sys_checktype(Janet x, JanetType t) { return janet_checktype(x, t); }
int janet_sys_truthy(Janet x) { return janet_truthy(x); }
Janet janet_sys_wrap_nil() { return janet_wrap_nil(); }
Janet janet_sys_wrap_true() { return janet_wrap_true(); }
Janet janet_sys_wrap_false() { return janet_wrap_false(); }
Janet janet_sys_wrap_boolean(int b) { return janet_wrap_boolean(b); }
Janet janet_sys_wrap_number(double r) { return janet_wrap_number(r); }

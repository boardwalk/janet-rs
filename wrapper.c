#include "vendor/janet/build/janet.h"

JanetType janet_sys_type(Janet x) { return janet_type(x); }
int janet_sys_checktype(Janet x, JanetType t) { return janet_checktype(x, t); }
int janet_sys_truthy(Janet x) { return janet_truthy(x); }

Janet janet_sys_wrap_nil() { return janet_wrap_nil(); }
Janet janet_sys_wrap_true() { return janet_wrap_true(); }
Janet janet_sys_wrap_false() { return janet_wrap_false(); }
Janet janet_sys_wrap_boolean(int b) { return janet_wrap_boolean(b); }
Janet janet_sys_wrap_number(double r) { return janet_wrap_number(r); }

int janet_sys_unwrap_boolean(Janet x) { return janet_unwrap_boolean(x); }
double janet_sys_unwrap_number(Janet x) { return janet_unwrap_number(x); }

Janet janet_sys_wrap_struct(JanetKV* x) { return janet_wrap_struct(x); }
Janet janet_sys_wrap_tuple(Janet* x) { return janet_wrap_tuple(x); }
Janet janet_sys_wrap_fiber(JanetFiber* x) { return janet_wrap_fiber(x); }
Janet janet_sys_wrap_array(JanetArray* x) { return janet_wrap_array(x); }
Janet janet_sys_wrap_table(JanetTable* x) { return janet_wrap_table(x); }
Janet janet_sys_wrap_buffer(JanetBuffer* x) { return janet_wrap_buffer(x); }
Janet janet_sys_wrap_string(uint8_t* x) { return janet_wrap_string(x); }
Janet janet_sys_wrap_symbol(uint8_t* x) { return janet_wrap_symbol(x); }
Janet janet_sys_wrap_keyword(uint8_t* x) { return janet_wrap_keyword(x); }
Janet janet_sys_wrap_abstract(void* x) { return janet_wrap_abstract(x); }
Janet janet_sys_wrap_function(JanetFunction* x) { return janet_wrap_function(x); }
Janet janet_sys_wrap_cfunction(JanetCFunction x) { return janet_wrap_cfunction(x); }

const JanetKV* janet_sys_unwrap_struct(Janet x) { return janet_unwrap_struct(x); }
const Janet* janet_sys_unwrap_tuple(Janet x) { return janet_unwrap_tuple(x); }
JanetFiber* janet_sys_unwrap_fiber(Janet x) { return janet_unwrap_fiber(x); }
JanetArray* janet_sys_unwrap_array(Janet x) { return janet_unwrap_array(x); }
JanetTable* janet_sys_unwrap_table(Janet x) { return janet_unwrap_table(x); }
JanetBuffer* janet_sys_unwrap_buffer(Janet x) { return janet_unwrap_buffer(x); }
const uint8_t* janet_sys_unwrap_string(Janet x) { return janet_unwrap_string(x); }
const uint8_t* janet_sys_unwrap_symbol(Janet x) { return janet_unwrap_symbol(x); }
const uint8_t* janet_sys_unwrap_keyword(Janet x) { return janet_unwrap_keyword(x); }
void* janet_sys_unwrap_abstract(Janet x) { return janet_unwrap_abstract(x); }
void* janet_sys_unwrap_pointer(Janet x) { return janet_unwrap_pointer(x); }
JanetFunction* janet_sys_unwrap_function(Janet x) { return janet_unwrap_function(x); }
JanetCFunction janet_sys_unwrap_cfunction(Janet x) { return janet_unwrap_cfunction(x); }

// Wrappers for various macros in janet.h
JanetType janet_sys_type(Janet x);
int janet_sys_checktype(Janet x, JanetType t);
int janet_sys_truthy(Janet x);
Janet janet_sys_wrap_nil();
Janet janet_sys_wrap_true();
Janet janet_sys_wrap_false();
Janet janet_sys_wrap_boolean(int b);
Janet janet_sys_wrap_number(double r);

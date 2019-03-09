// Wrappers for various macros in janet.h
JanetType janet_sys_type(Janet x);
int janet_sys_checktype(Janet x, JanetType t);
int janet_sys_truthy(Janet x);

Janet janet_sys_wrap_nil();
Janet janet_sys_wrap_true();
Janet janet_sys_wrap_false();
Janet janet_sys_wrap_boolean(int b);
Janet janet_sys_wrap_number(double r);

int janet_sys_unwrap_boolean(Janet x);
double janet_sys_unwrap_number(Janet x);

Janet janet_sys_wrap_struct(JanetKV* x);
Janet janet_sys_wrap_tuple(Janet* x);
Janet janet_sys_wrap_fiber(JanetFiber* x);
Janet janet_sys_wrap_array(JanetArray* x);
Janet janet_sys_wrap_table(JanetTable* x);
Janet janet_sys_wrap_buffer(JanetBuffer* x);
Janet janet_sys_wrap_string(uint8_t* x);
Janet janet_sys_wrap_symbol(uint8_t* x);
Janet janet_sys_wrap_keyword(uint8_t* x);
Janet janet_sys_wrap_abstract(void* x);
Janet janet_sys_wrap_function(JanetFunction* x);
Janet janet_sys_wrap_cfunction(JanetCFunction x);

const JanetKV* janet_sys_unwrap_struct(Janet x);
const Janet* janet_sys_unwrap_tuple(Janet x);
JanetFiber* janet_sys_unwrap_fiber(Janet x);
JanetArray* janet_sys_unwrap_array(Janet x);
JanetTable* janet_sys_unwrap_table(Janet x);
JanetBuffer* janet_sys_unwrap_buffer(Janet x);
const uint8_t* janet_sys_unwrap_string(Janet x);
const uint8_t* janet_sys_unwrap_symbol(Janet x);
const uint8_t* janet_sys_unwrap_keyword(Janet x);
void* janet_sys_unwrap_abstract(Janet x);
void* janet_sys_unwrap_pointer(Janet x);
JanetFunction* janet_sys_unwrap_function(Janet x);
JanetCFunction janet_sys_unwrap_cfunction(Janet x);

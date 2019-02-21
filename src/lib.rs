#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod test {
    use super::*;
    use std::ffi::CString;

    #[test]
    fn test_janet() {
        unsafe {
            assert_eq!(janet_init(), 0);
            let mut out = janet_sys_wrap_nil();

            let source_str = CString::new("(print \"Hello, world!\")").unwrap();
            let file_str = CString::new(file!()).unwrap();
            assert_eq!(janet_dostring(janet_core_env(), source_str.as_ptr(), file_str.as_ptr(), &mut out), 0);

            janet_deinit();

        }
    }
}

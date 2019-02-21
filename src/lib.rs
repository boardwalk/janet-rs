#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod test {
    use super::*;
    use std::ffi::CString;
    use std::ffi::CStr;

    #[test]
    fn test_version() {
        let janet_version = CStr::from_bytes_with_nul(JANET_VERSION)
            .unwrap()
            .to_string_lossy();
        assert_eq!(janet_version, env!("CARGO_PKG_VERSION"));
    }

    #[test]
    fn test_dostring() {
        unsafe {
            assert_eq!(janet_init(), 0);

            let source = CString::new("(+ 3 4)").unwrap();
            let file = CString::new(file!()).unwrap();
            let mut out = janet_sys_wrap_nil();
            assert_eq!(janet_dostring(janet_core_env(), source.as_ptr(), file.as_ptr(), &mut out), 0);
            assert_eq!(janet_sys_type(out), JanetType_JANET_NUMBER);
            assert_eq!(janet_sys_unwrap_number(out), 7.0);

            janet_deinit();

        }
    }
}
